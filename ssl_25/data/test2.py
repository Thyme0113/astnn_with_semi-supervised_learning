import numpy as np
import pandas as pd
data = pd.read_pickle('c/oj_clone_ids.pkl')
train_num = 10
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

print(fibRecursive_fibLoop)

# train data
# similar data
train_fibRecursive_fibLoop = fibRecursive_fibLoop.iloc[:train_num]
train_fibLoop_fibRecursive = fibLoop_fibRecursive.iloc[:train_num]
train_factRecursive_factLoop = factRecursive_factLoop.iloc[:train_num]
train_factLoop_factRecursive = factLoop_factRecursive.iloc[:train_num]

# unsimilar data
train_fibRecursive_factLoop = fibRecursive_factLoop.iloc[:train_num]
train_fibLoop_factRecursive = fibLoop_factRecursive.iloc[:train_num]
train_factRecursive_fibLoop = factRecursive_fibLoop.iloc[:train_num]
train_factLoop_fibRecursive = factLoop_fibRecursive.iloc[:train_num]

# test data
# similar data
test_fibRecursive_fibLoop = fibRecursive_fibLoop.iloc[train_num:train_num+200]
test_fibLoop_fibRecursive = fibLoop_fibRecursive.iloc[train_num:train_num+200]
test_factRecursive_factLoop = factRecursive_factLoop.iloc[train_num:train_num+200]
test_factLoop_factRecursive = factLoop_factRecursive.iloc[train_num:train_num+200]
test_gcdRecursive_gcdLoop = gcdRecursive_gcdLoop.iloc[train_num:train_num+200]
test_gcdLoop_gcdRecursive = gcdLoop_gcdRecursive.iloc[train_num:train_num+200]

# unsimilar data
test_fibRecursive_factLoop = fibRecursive_factLoop.iloc[train_num:train_num+100]
test_fibLoop_factRecursive = fibLoop_factRecursive.iloc[train_num:train_num+100]

test_fibRecursive_gcdLoop = fibRecursive_gcdLoop.iloc[train_num:train_num+100]
test_fibLoop_gcdRecursive = fibLoop_gcdRecursive.iloc[train_num:train_num+100]

test_factRecursive_fibLoop = factRecursive_fibLoop.iloc[train_num:train_num+100]
test_factLoop_fibRecursive = factLoop_fibRecursive.iloc[train_num:train_num+100]

test_factRecursive_gcdLoop = factRecursive_gcdLoop.iloc[train_num:train_num+100]
test_factLoop_gcdRecursive = factLoop_gcdRecursive.iloc[train_num:train_num+100]

test_gcdRecursive_fibLoop = gcdRecursive_fibLoop.iloc[train_num:train_num+100]
test_gcdLoop_fibRecursive = gcdLoop_fibRecursive.iloc[train_num:train_num+100]

test_gcdRecursive_factLoop = gcdRecursive_factLoop.iloc[train_num:train_num+100]
test_gcdLoop_factRecursive = gcdLoop_factRecursive.iloc[train_num:train_num+100]

columns = ['id1', 'id2', 'label']

train = pd.DataFrame(np.vstack([
    train_fibRecursive_fibLoop,
    train_fibLoop_fibRecursive,
    train_factRecursive_factLoop, 
    train_factLoop_factRecursive, 
    train_fibRecursive_factLoop,
    train_fibLoop_factRecursive,
    train_factRecursive_fibLoop,
    train_factLoop_fibRecursive
]), columns=columns).sample(frac=1, random_state=707)

test =  pd.DataFrame(np.vstack([
    test_fibRecursive_fibLoop,
    test_fibLoop_fibRecursive,
    test_factRecursive_factLoop,
    test_factLoop_factRecursive,
    test_gcdRecursive_gcdLoop,
    test_gcdLoop_gcdRecursive,
    test_fibRecursive_factLoop,
    test_fibLoop_factRecursive,
    test_fibRecursive_gcdLoop,
    test_fibLoop_gcdRecursive,
    test_factRecursive_fibLoop,
    test_factLoop_fibRecursive,
    test_factRecursive_gcdLoop,
    test_factLoop_gcdRecursive,
    test_gcdRecursive_fibLoop,
    test_gcdLoop_fibRecursive,
    test_gcdRecursive_factLoop,
    test_gcdLoop_factRecursive
]), columns=columns).sample(frac=1, random_state=808)

print(train.shape)
print(test.shape)
