import pandas as pd
import os
import re
path = './src/'
subdir_list = [f.path for f in os.scandir(path) if f.is_dir()]
aList = []
for dir in subdir_list:
    for file in os.listdir(dir):
        relative_filename = os.path.join(dir, file)
        if os.path.isfile(relative_filename):
            pardir = dir.split('/')[2]
            lable = None
            j = ''
            if pardir == 'factorial':
                label = 0
                j += '11'

            elif pardir == 'fibonacci':
                label = 1
                j += '22'
            else:
                label = 2
                j += '33'
            
            if 'recursive' in file:
                label += 3
                j += '44'
            else:
                j += '55'
            
            num = re.search(r'\d+', file).group()
            if len(num) < 2:
                num = '0' + num
            
            j += num
            with open(relative_filename) as f:
                s = f.read()
                aList.append([int(j), s, label])
df = pd.DataFrame(aList)
print(df.shape)
pd.to_pickle(df, './c/programs.pkl')
