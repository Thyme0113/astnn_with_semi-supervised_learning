int F[45];

int fib(int n){
  if (F[n]) return F[n];
  if (n==0||n==1) F[n]=1;
  else F[n]=fib(n-1)+fib(n-2);
  return F[n];
}

int main(){
  int n;
  cin >>n;
  cout << fib(n)<<endl;
  return 0;
}
