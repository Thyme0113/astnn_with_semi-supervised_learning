int  memo[1000];
int fib(int n){
  if(memo[n] == -1000000000){ memo[n] = fib(n - 1) + fib(n - 2); }
  return memo[n];
}

int main(void){
  int n;
  cin >> n;
  
  memset(memo, -1000000000, sizeof(memo));
  memo[0] = memo[1] = 1; 
  
  cout << fib(n) << endl;
  return 0;
}
