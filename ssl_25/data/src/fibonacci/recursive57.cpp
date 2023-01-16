long long fib[50];
long long dfs(int n) {
    if (fib[n] > 0) return fib[n];
    if (n == 0 || n == 1) return 1;
    return fib[n] = dfs(n-1) + dfs(n-2);
}
int main(void) {
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}
