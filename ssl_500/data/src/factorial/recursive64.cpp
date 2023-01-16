long long int dfs(long long int n){
    if(n == 0) return 1;
    else return dfs(n - 1) * n;
}

int main(){
    long long int n;
    cin >>n;
    cout <<dfs(n) <<endl;
    return 0;
}
