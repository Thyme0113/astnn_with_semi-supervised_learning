int dp[44]= {};

int rec(int N){
  if(N==0 || N == 1) return 1;
  else { 
    if(dp[N] > 0) return dp[N];
    dp[N] = rec(N-1)+ rec(N-2);
    return dp[N];
    }
}


int main()
{
  int N; cin >> N;
  cout <<  rec(N) << endl;


}

