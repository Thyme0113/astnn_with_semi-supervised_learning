int gcd(int x, int y) {
  return (y == 0) ? x : gcd(y, x % y);
}

int main() {
  int a, b;
  cin >> a >> b;

  if (a < b) swap(a, b);

  int ans = gcd(a, b);
  printf("%d\n", ans);

  return 0;
}
