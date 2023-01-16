int main(void) {
   cin.tie(0);
   sync_with_stdio(false);
   cout << fixed << setprecision(7);
   int n; cin >> n;
   long long fib[46];
   fib[0]=1;
   fib[1]=1;
   for(int i=2;i<=n;i++) {
      fib[i]=fib[i-1]+fib[i-2];
   }
   cout << fib[n] << endl;
   return 0;
}
