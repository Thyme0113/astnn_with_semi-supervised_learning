import pandas as pd
df = pd.read_pickle('./c/programs.pkl')
print(df.shape)
new_df = df.rename(columns={0:'id', 1:'code', 2:'label'})
df_list = []
for i in range(6):
    df_i = new_df.loc[new_df['label']==i].reset_index(drop=True)
    df_i['tmp'] = 1
    df_list.append(df_i)

new_df_list = []
for i in range(6):
    if i in [0, 1, 2]:
        new_df_list.append(pd.merge(df_list[i], df_list[3], on='tmp', how='outer'))
        new_df_list.append(pd.merge(df_list[i], df_list[4], on='tmp', how='outer'))
        new_df_list.append(pd.merge(df_list[i], df_list[5], on='tmp', how='outer'))
    else:
        new_df_list.append(pd.merge(df_list[i], df_list[0], on='tmp', how='outer'))
        new_df_list.append(pd.merge(df_list[i], df_list[1], on='tmp', how='outer'))
        new_df_list.append(pd.merge(df_list[i], df_list[2], on='tmp', how='outer'))
for new_df_i in new_df_list:
    new_df_i['label'] = (new_df_i['label_x']-new_df_i['label_y']).abs()
    new_df_i['label'].replace([0, 1, 2, 4, 5], 0, inplace=True)
    new_df_i['label'].replace([3], 1, inplace=True)
df = pd.concat(new_df_list, ignore_index=True)[['id_x', 'id_y', 'label']].rename(columns={'id_x':'id1', 'id_y':'id2'})
df.to_pickle('./c/oj_clone_ids.pkl')
print(df.shape)
