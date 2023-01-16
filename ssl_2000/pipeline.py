import numpy as np
import pandas as pd
import os
import sys
import warnings
warnings.filterwarnings('ignore')
    
class Pipeline:
    def __init__(self, root, language):
        self.root = root
        self.language = language
        self.sources = None
        self.blocks = None
        self.pairs = None
        self.train_file_path = None
        # self.dev_file_path = None
        self.test_file_path = None
        self.size = None

    # parse source code
    def parse_source(self, output_file, option):
        path = self.root+self.language+'/'+output_file
        if os.path.exists(path) and option == 'existing':
            source = pd.read_pickle(path)
        else:
            if self.language is 'c':
                from pycparser import c_parser
                parser = c_parser.CParser()
                source = pd.read_pickle(self.root+self.language+'/programs.pkl')
                source.columns = ['id', 'code', 'label']
                source['code'] = source['code'].apply(parser.parse)
                source.to_pickle(path)
            else:
                import javalang
                def parse_program(func):
                    tokens = javalang.tokenizer.tokenize(func)
                    parser = javalang.parser.Parser(tokens)
                    tree = parser.parse_member_declaration()
                    return tree
                source = pd.read_csv(self.root+self.language+'/bcb_funcs_all.tsv', sep='\t', header=None, encoding='utf-8')
                source.columns = ['id', 'code']
                source['code'] = source['code'].apply(parse_program)
                source.to_pickle(path)
        self.sources = source
        return source

    # create clone pairs
    def read_pairs(self, filename):
        pairs = pd.read_pickle(self.root+self.language+'/'+filename)
        self.pairs = pairs

    # split data for training, developing and testing
    def split_data(self, train_num):
        data_path = self.root+self.language+'/'
        data = self.pairs

        # similar_data
        fibRecursive_fibLoop = data.query('id1 <= 224499 and id1 >= 224400 and id2 <= 225599 and id2 >= 225500').sample(frac=1, random_state=610)
        fibLoop_fibRecursive = data.query('id1 <= 225599 and id1 >= 225500 and id2 <= 224499 and id2 >= 224400').sample(frac=1, random_state=620)
        factRecursive_factLoop = data.query('id1 <= 114499 and id1 >= 114400 and id2 <= 115599 and id2 >= 115500').sample(frac=1, random_state=630)
        factLoop_factRecursive = data.query('id1 <= 115599 and id1 >= 115500 and id2 <= 114499 and id2 >= 114400').sample(frac=1, random_state=640)
        gcdRecursive_gcdLoop = data.query('id1 <= 334499 and id1 >= 334400 and id2 <= 335599 and id2 >= 335500').sample(frac=1, random_state=650)
        gcdLoop_gcdRecursive = data.query('id1 <= 335599 and id1 >= 335500 and id2 <= 334499 and id2 >= 334400').sample(frac=1, random_state=660)
        # unsimilar_data
        fibRecursive_factLoop = data.query('id1 <= 224499 and id1 >= 224400 and id2 <= 115599 and id2 >= 115500').sample(frac=1, random_state=15)
        fibLoop_factRecursive = data.query('id1 <= 225599 and id1 >= 225500 and id2 <= 114499 and id2 >= 114400').sample(frac=1, random_state=30)

        fibRecursive_gcdLoop = data.query('id1 <= 224499 and id1 >= 224400 and id2 <= 335599 and id2 >= 335500').sample(frac=1, random_state=45)
        fibLoop_gcdRecursive = data.query('id1 <= 225599 and id1 >= 225500 and id2 <= 334499 and id2 >= 334400').sample(frac=1, random_state=60)

        factRecursive_fibLoop = data.query('id1 <= 114499 and id1 >= 114400 and id2 <= 225599 and id2 >= 225500').sample(frac=1, random_state=75)
        factLoop_fibRecursive = data.query('id1 <= 115599 and id1 >= 115500 and id2 <= 224499 and id2 >= 224400').sample(frac=1, random_state=90)

        factRecursive_gcdLoop = data.query('id1 <= 114499 and id1 >= 114400 and id2 <= 335599 and id2 >= 335500').sample(frac=1, random_state=105)
        factLoop_gcdRecursive = data.query('id1 <= 115599 and id1 >= 115500 and id2 <= 334499 and id2 >= 334400').sample(frac=1, random_state=120)

        gcdRecursive_fibLoop = data.query('id1 <= 334499 and id1 >= 334400 and id2 <= 115599 and id2 >= 115500').sample(frac=1, random_state=135)
        gcdLoop_fibRecursive = data.query('id1 <= 335599 and id1 >= 335500 and id2 <= 114499 and id2 >= 114400').sample(frac=1, random_state=150)

        gcdRecursive_factLoop = data.query('id1 <= 334499 and id1 >= 334400 and id2 <= 225599 and id2 >= 225500').sample(frac=1, random_state=165)
        gcdLoop_factRecursive = data.query('id1 <= 335599 and id1 >= 335500 and id2 <= 224499 and id2 >= 224400').sample(frac=1, random_state=180)

        # train data
        # similar data
        train_fibRecursive_fibLoop = fibRecursive_fibLoop.iloc[:train_num]
        
        train_factRecursive_factLoop = factRecursive_factLoop.iloc[:train_num]
        
        #train_gcdRecursive_gcdLoop = gcdRecursive_gcdLoop.iloc[:train_num]
        

        # unsimilar data
        train_fibRecursive_factLoop = fibRecursive_factLoop.iloc[:train_num]
       
        #train_fibRecursive_gcdLoop = fibRecursive_gcdLoop.iloc[:train_num]

        train_factRecursive_fibLoop = factRecursive_fibLoop.iloc[:train_num]
        

        #train_factRecursive_gcdLoop = factRecursive_gcdLoop.iloc[:train_num]

        #train_gcdRecursive_fibLoop = gcdRecursive_fibLoop.iloc[:train_num]

        #train_gcdRecursive_factLoop = gcdRecursive_factLoop.iloc[:train_num]

        # test data
        # similar data
        test_fibRecursive_fibLoop = fibRecursive_fibLoop.iloc[train_num:train_num+500]
        
        test_factRecursive_factLoop = factRecursive_factLoop.iloc[train_num:train_num+500]
        
        test_gcdRecursive_gcdLoop = gcdRecursive_gcdLoop.iloc[train_num:train_num+500]
       
        # unsimilar data
        test_fibRecursive_factLoop = fibRecursive_factLoop.iloc[train_num:train_num+250]
        
        test_fibRecursive_gcdLoop = fibRecursive_gcdLoop.iloc[train_num:train_num+250]

        test_factRecursive_fibLoop = factRecursive_fibLoop.iloc[train_num:train_num+250]
        

        test_factRecursive_gcdLoop = factRecursive_gcdLoop.iloc[train_num:train_num+250]
        
        test_gcdRecursive_fibLoop = gcdRecursive_fibLoop.iloc[train_num:train_num+250]
        
        test_gcdRecursive_factLoop = gcdRecursive_factLoop.iloc[train_num:train_num+250]
        

        columns = ['id1', 'id2', 'label']
        train =  pd.DataFrame(np.vstack([
            train_fibRecursive_fibLoop,
            train_factRecursive_factLoop,
            #train_gcdRecursive_gcdLoop,
            train_fibRecursive_factLoop,
            #train_fibRecursive_gcdLoop,
            train_factRecursive_fibLoop,
            #train_factRecursive_gcdLoop,
            #train_gcdRecursive_fibLoop,
            #train_gcdRecursive_factLoop,
        ]), columns=columns).sample(frac=1, random_state=707)
        test =  pd.DataFrame(np.vstack([
            test_fibRecursive_fibLoop,
            test_factRecursive_factLoop,
            test_gcdRecursive_gcdLoop,
            test_fibRecursive_factLoop,
            test_fibRecursive_gcdLoop,
            test_factRecursive_fibLoop,
            test_factRecursive_gcdLoop,
            test_gcdRecursive_fibLoop,
            test_gcdRecursive_factLoop,
        ]), columns=columns).sample(frac=1, random_state=808)

        def check_or_create(path):
            if not os.path.exists(path):
                os.mkdir(path)
        train_path = data_path+'train/'
        check_or_create(train_path)
        self.train_file_path = train_path+'train_.pkl'
        train.to_pickle(self.train_file_path)

        test_path = data_path+'test/'
        check_or_create(test_path)
        self.test_file_path = test_path+'test_.pkl'
        test.to_pickle(self.test_file_path)

    # construct dictionary and train word embedding
    def dictionary_and_embedding(self, input_file, size):
        self.size = size
        data_path = self.root+self.language+'/'
        if not input_file:
            input_file = self.train_file_path
        pairs = pd.read_pickle(input_file)
        train_ids = pairs['id1'].append(pairs['id2']).unique()

        trees = self.sources.set_index('id',drop=False).loc[train_ids]
        if not os.path.exists(data_path+'train/embedding'):
            os.mkdir(data_path+'train/embedding')
        if self.language is 'c':
            sys.path.append('../')
            from prepare_data import get_sequences as func
        else:
            from utils import get_sequence as func

        def trans_to_sequences(ast):
            sequence = []
            func(ast, sequence)
            return sequence
        corpus = trees['code'].apply(trans_to_sequences)
        str_corpus = [' '.join(c) for c in corpus]
        trees['code'] = pd.Series(str_corpus)
        # trees.to_csv(data_path+'train/programs_ns.tsv')

        from gensim.models.word2vec import Word2Vec
        w2v = Word2Vec(corpus, size=size, workers=16, sg=1, max_final_vocab=3000)
        w2v.save(data_path+'train/embedding/node_w2v_' + str(size))

    # generate block sequences with index representations
    def generate_block_seqs(self):
        if self.language is 'c':
            from prepare_data import get_blocks as func
        else:
            from utils import get_blocks_v1 as func
        from gensim.models.word2vec import Word2Vec

        word2vec = Word2Vec.load(self.root+self.language+'/train/embedding/node_w2v_' + str(self.size)).wv
        vocab = word2vec.vocab
        max_token = word2vec.syn0.shape[0]

        def tree_to_index(node):
            token = node.token
            result = [vocab[token].index if token in vocab else max_token]
            children = node.children
            for child in children:
                result.append(tree_to_index(child))
            return result

        def trans2seq(r):
            blocks = []
            func(r, blocks)
            tree = []
            for b in blocks:
                btree = tree_to_index(b)
                tree.append(btree)
            return tree
        trees = pd.DataFrame(self.sources, copy=True)
        trees['code'] = trees['code'].apply(trans2seq)
        if 'label' in trees.columns:
            trees.drop('label', axis=1, inplace=True)
        self.blocks = trees

    # merge pairs
    def merge(self,data_path,part):
        pairs = pd.read_pickle(data_path)
        pairs['id1'] = pairs['id1'].astype(int)
        pairs['id2'] = pairs['id2'].astype(int)
        df = pd.merge(pairs, self.blocks, how='left', left_on='id1', right_on='id')
        df = pd.merge(df, self.blocks, how='left', left_on='id2', right_on='id')
        df.drop(['id_x', 'id_y'], axis=1,inplace=True)
        df.dropna(inplace=True)

        df.to_pickle(self.root+self.language+'/'+part+'/blocks.pkl')

    # run for processing data to train
    def run(self):
        print('parse source code...')
        self.parse_source(output_file='ast.pkl',option='existing')
        print('read id pairs...')
        if self.language is 'c':
            self.read_pairs('oj_clone_ids.pkl')
        else:
            self.read_pairs('bcb_pair_ids.pkl')
        print('split data...')
        train_num = 2000
        self.split_data(train_num)
        print('train word embedding...')
        self.dictionary_and_embedding(None,128)
        print('generate block sequences...')
        self.generate_block_seqs()
        print('merge pairs and blocks...')
        self.merge(self.train_file_path, 'train')
        # self.merge(self.dev_file_path, 'dev')
        self.merge(self.test_file_path, 'test')


import argparse
parser = argparse.ArgumentParser(description="Choose a dataset:[c|java]")
parser.add_argument('--lang')
args = parser.parse_args()
if not args.lang:
    print("No specified dataset")
    exit(1)
ppl = Pipeline('data/', str(args.lang))
ppl.run()


