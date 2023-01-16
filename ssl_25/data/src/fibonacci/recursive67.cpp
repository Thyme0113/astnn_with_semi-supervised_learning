long long dp[50];
long long fib(long long n){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}

int main()
{
    long long n;
    cin >> n;
    for(long long i=0;i<50;i++)
    {
        dp[i]=-1;
    }
    cout << fib(n) << endl;
    
    return 0;
} 
