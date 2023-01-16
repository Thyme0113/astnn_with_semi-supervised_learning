int fib(int n , int t , int p1 , int p2){

  if( n==t )return p1+p2;

  return fib(n+1,t,p2,p1+p2);
  
}


int main(){

  int n;

  cin >> n;

  if(n==0 || n==1)cout << 1 << endl;
  else
    cout << fib(2,n,1,1) << endl;

  return 0;
}
