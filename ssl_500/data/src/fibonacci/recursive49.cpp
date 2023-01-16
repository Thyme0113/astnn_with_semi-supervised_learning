int mem[50];

long long fib(int n){
  if(mem[n]!=-1)
    return mem[n];
  
  if(n==0||n==1)
    return mem[n]=1;

  return mem[n]=fib(n-1)+fib(n-2);
}

main()
{

  int n;
  
  cin >> n;
  
  for(int i=0;i<50;i++){
    mem[i]=-1;
  }

  cout << fib(n) << endl;

  return (0);
}

