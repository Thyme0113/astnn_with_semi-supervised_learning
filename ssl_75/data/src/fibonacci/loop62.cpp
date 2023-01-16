int main(){
  long long int i,n,dp[50];
  scanf("%lld\n",&n);
  dp[0]=1,dp[1]=1;
  for(i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  printf("%lld\n",dp[n]);
  return 0;
}
