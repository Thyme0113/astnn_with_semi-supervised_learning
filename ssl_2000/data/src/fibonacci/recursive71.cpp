int f[50]={};

int fib(int n){
  if(n==0||n==1)return f[n]=1;
  if(f[n]!=0)return f[n];
  return f[n]=fib(n-1)+fib(n-2);
}

signed main(){
  int n;
  cin>>n;
  cout<<fib(n)<<endl;

  return 0;
}
