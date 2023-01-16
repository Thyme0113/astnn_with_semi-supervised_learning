import pandas as pd
import torch
import time
import numpy as np
import warnings
from gensim.models.word2vec import Word2Vec
from model import BatchProgramCC
from torch.autograd import Variable
from sklearn.metrics import precision_recall_fscore_support
from scipy.spatial import distance
warnings.filterwarnings('ignore')



def split_dataset(dataset):
    x1, x2, labels = [], [], []
    id1_list, id2_list = [], []
    dummy0_list, dummy1_list = [], []
    for _, item in dataset.iterrows():
        x1.append(item['code_x'])
        x2.append(item['code_y'])
        labels.append([item['label']])

        id1_list.append(item['id1'])
        id2_list.append(item['id2'])
        
        dummy0_list.append([item['dummy0']])
        dummy1_list.append([item['dummy1']])
    return x1, x2, torch.FloatTensor(labels), torch.IntTensor(id1_list), torch.IntTensor(id2_list), np.array(dummy0_list), np.array(dummy1_list)


if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description="Choose a dataset:[c|java]")
    parser.add_argument('--lang')
    args = parser.parse_args()
    if not args.lang:
        print("No specified dataset")
        exit(1)
    root = 'data/'
    lang = args.lang
    categories = 1
    if lang == 'java':
        categories = 5
    print("Train for ", str.upper(lang))
    train_data = pd.read_pickle(root+lang+'/train/blocks.pkl').sample(frac=1, random_state=234)
    test_data = pd.read_pickle(root+lang+'/test/blocks.pkl').sample(frac=1, random_state=345)
    print("loaded train, test data, next word2vec load ..")
    word2vec = Word2Vec.load(root+lang+"/train/embedding/node_w2v_128").wv
    MAX_TOKENS = word2vec.syn0.shape[0]
    EMBEDDING_DIM = word2vec.syn0.shape[1]
    embeddings = np.zeros((MAX_TOKENS + 1, EMBEDDING_DIM), dtype="float32")
    embeddings[:word2vec.syn0.shape[0]] = word2vec.syn0

    print("loaded word2vec, next model load ...")
    HIDDEN_DIM = 100
    ENCODE_DIM = 128
    LABELS = 1
    EPOCHS = 5
    BATCH_SIZE = 32
    USE_GPU = False
    
    model = BatchProgramCC(EMBEDDING_DIM,HIDDEN_DIM,MAX_TOKENS+1,ENCODE_DIM,LABELS,BATCH_SIZE,
                                   USE_GPU, embeddings)
    if USE_GPU:
        model.cuda()

    print("prepair model ...")
    parameters = model.parameters()
    optimizer = torch.optim.Adamax(parameters)
    loss_function = torch.nn.BCELoss()

    print(train_data)
    precision, recall, f1 = 0, 0, 0
    print('Start training...')
    for t in range(1, categories+1):
        if lang == 'java':
            train_data_t = train_data[train_data['label'].isin([t, 0])]
            train_data_t.loc[train_data_t['label'] > 0, 'label'] = 1

            test_data_t = test_data[test_data['label'].isin([t, 0])]
            test_data_t.loc[test_data_t['label'] > 0, 'label'] = 1
        else:
            train_data_t, test_data_t = train_data, test_data
            
        train_data_t['dummy0'] = (train_data_t['label']-1).abs()
        train_data_t['dummy1'] = train_data_t['label']
        train_data_t['is_test'] = False

        test_data_t['dummy0'] = 0
        test_data_t['dummy1'] = 0
        test_data_t['is_test'] = True
        
        all_data = pd.concat([train_data_t, test_data_t]).sample(frac=1, random_state=456).reset_index(drop=True)

        # training procedure
        for epoch in range(EPOCHS):
            start_time = time.time()
            # training epoch
            total_acc = 0.0
            total_loss = 0.0
            total = 0.0
            
            train1_inputs, train2_inputs, train_labels, _, __, ___, ____  = split_dataset(train_data_t)
            # if USE_GPU:
            #     train1_inputs, train2_inputs, train_labels = train1_inputs, train2_inputs, train_labels.cuda()

            model.zero_grad()
            model.batch_size = len(train_labels)
            model.hidden = model.init_hidden()
            output = model(train1_inputs, train2_inputs)

            loss = loss_function(output, Variable(train_labels))
            loss.backward()
            optimizer.step()
        print("Testing-%d..."%t)
        # testing procedure
        total_loss = 0.0
        total = 0.0
        
        test1_inputs, test2_inputs, test_labels, test_id1, test_id2, test_dummy0, test_dummy1  = split_dataset(all_data)
        # if USE_GPU:
        #     test_labels = test_labels.cuda()
        
        model.batch_size = len(test_labels)
        model.hidden = model.init_hidden()
        output = model(test1_inputs, test2_inputs)
        
        # calc semi supervised learning
        hiddenVector = model.requireHiddenVec(test1_inputs, test2_inputs).detach().numpy()
        
        
        distanceMatrix = distance.cdist(hiddenVector, hiddenVector, metric='euclidean')
        # hiddenVector = model.requireHiddenVec(test1_inputs, test2_inputs).detach().numpy()
        # normalizedHiddenVector = hiddenVector / np.linalg.norm(hiddenVector)
        
        # distanceMatrix = distance.cdist(normalizedHiddenVector, normalizedHiddenVector, metric='euclidean')
        
        median = np.median(distanceMatrix)
        
        similarityMatrix = np.exp(-np.power(distanceMatrix,2) / 2 / median**2)
        
        similarityMatrix = similarityMatrix - np.diag(np.diag(similarityMatrix))
        
        diagonalMatrix = np.diag(np.sum(similarityMatrix, axis=0)**(-0.5))
        
        laplacianMatrix = diagonalMatrix @ similarityMatrix @ diagonalMatrix
        
        labelMatrix = np.hstack((np.reshape(test_dummy0,(-1,1)), np.reshape(test_dummy1,(-1,1))))
        
        identityMatrix = np.eye(model.batch_size)
        
        alpha = 0.5

        F = np.linalg.inv(identityMatrix - alpha * laplacianMatrix) @ labelMatrix
        df_F = pd.DataFrame(F).rename(columns = {0:'f0', 1:'f1'})
        
        semi_predicted = np.argmax(F, axis=1)
        
        loss = loss_function(output, Variable(test_labels))

        # calc testing acc
        output_data = np.reshape(output.data.cpu().numpy(), (-1,))
        predicted = np.reshape((output.data > 0.5).cpu().numpy(), (-1,))
        true = np.reshape(test_labels.cpu().numpy(), (-1,))

        id1_list = np.reshape(test_id1.cpu().numpy(), (-1,))
        id2_list = np.reshape(test_id2.cpu().numpy(), (-1,))

        total += len(test_labels)
        total_loss += loss.item() * len(test_labels)

        df = pd.DataFrame([
            output_data, predicted, semi_predicted, true, id1_list, id2_list
        ]).T.rename(columns = {0:'output_data', 1: 'pred', 2:'semi_pred', 3:'true', 4:'id1', 5:'id2'})
        new_df = pd.concat([df, df_F], axis=1)
        
        new_df = new_df[all_data['is_test']]
        new_df.to_csv('test.csv', index=False)
        if lang == 'java':
            weights = [0, 0.005, 0.001, 0.002, 0.010, 0.982]
            p, r, f, _ = precision_recall_fscore_support(trues, predicts, average='binary')
            precision += weights[t] * p
            recall += weights[t] * r
            f1 += weights[t] * f
            print("Type-" + str(t) + ": " + str(p) + " " + str(r) + " " + str(f))
        else:
            trues = new_df['true'].values
            predicts = new_df['pred'].values
            precision, recall, f1, _ = precision_recall_fscore_support(trues, predicts, average='binary')
            print("Total testing results(P,R,F1):%.3f, %.3f, %.3f" % (precision, recall, f1))
            
            semi_predicts = new_df['semi_pred'].values
            precision, recall, f1, _ = precision_recall_fscore_support(trues, semi_predicts, average='binary')
            print("Semi testing results(P,R,F1):%.3f, %.3f, %.3f" % (precision, recall, f1))

    
    
