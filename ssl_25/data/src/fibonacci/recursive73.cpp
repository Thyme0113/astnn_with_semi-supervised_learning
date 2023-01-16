int dp[50];

int f(int n) {
    if(n == 0 || n == 1) return 1;
    if(dp[n]) {
        return dp[n];
    } else {
        return dp[n] = f(n-1) + f(n-2);
    }
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
}
