int main() {
  int n;
  cin >> n;
  int res = 1;
  for(int i = 2; i <= n; ++i) res *= i;
  cout << res << endl;
  return 0;
}
