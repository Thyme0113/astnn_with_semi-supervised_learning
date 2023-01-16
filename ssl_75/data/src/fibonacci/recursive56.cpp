int dp[45];

int fibo(int n)
{
  if (dp[n] != -1){
    return (dp[n]);
  }

  if (n == 0 || n == 1){
    return (1);
  }
  return (dp[n] = fibo(n - 1) + fibo(n - 2));
}

signed main()
{
  sync_with_stdio(false);
  int n;
  cin >> n;
  fill(dp, dp + 45, -1);
  print(fibo(n));
  return (0);
}
