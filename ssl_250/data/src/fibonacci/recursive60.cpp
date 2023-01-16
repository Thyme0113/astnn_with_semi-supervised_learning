int memo[1000];
int fib(int n){
    if(n == 0 || n == 1){
        return (memo[n] = 1);
    }else{
        if(memo[n-2] == 0) memo[n-2] = fib(n-2);
        if(memo[n-1] == 0) memo[n-1] = fib(n-1);
        if(memo[n] == 0) memo[n] = memo[n-2] + memo[n-1];
        return memo[n];
    }
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
