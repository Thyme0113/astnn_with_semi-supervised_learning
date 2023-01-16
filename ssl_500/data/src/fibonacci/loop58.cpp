int main() {
  int dp[MAX];
  dp[0] = dp[1] = 1;
  for (int i = 2; i < 45; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  int n;
  cin >> n;
  cout << dp[n] << endl;

  return 0;
}
