long long memo[25];

long long dfs(int n) {
    if (memo[n] > 0) return memo[n];
    if (n == 0 || n == 1) return 1;
    else return memo[n] = n * dfs(n-1);
}

int main(void) {
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}
