int fib[45];
int n;

int main()
{
  cin >> n;

  fib[0] = fib[1] = 1;
  for(int i=0;i<n-1;++i) {
    fib[i+2] = fib[i] + fib[i+1];
  }

  cout << fib[n] << endl;

  return 0;
}
