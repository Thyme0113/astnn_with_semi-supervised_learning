long long int fibonatti[10000];
long long int  dp[10000];
int calc(int n){
  if(n <= 1) return 1;
  if(dp[n] != -1)return dp[n];
  fibonatti[n] = calc(n - 1) + calc(n - 2);
  return dp[n] = fibonatti[n];
}

int main(int argc, char *argv[]){
  int n;
  cin >> n;
  fibonatti[0] = fibonatti[1] = 1;
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  dp[0] = dp[1] = 1;
  cout << calc(n) << endl;
  return 0;
}
