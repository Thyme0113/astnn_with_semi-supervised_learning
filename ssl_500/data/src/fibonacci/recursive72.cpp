long long dp[50];
int fib(int x) {
    if(dp[x] != -1) return dp[x];
    if(x == 0 || x == 1) return dp[x] = 1;
    return dp[x] = fib(x-1) + fib(x-2);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
}
