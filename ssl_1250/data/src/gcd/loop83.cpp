int gcd(int a, int b) {
  while( b ) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

int main(void) {
  int x, y;
  scanf("%d%d", &x, &y);
  printf("%d\n", gcd(x, y));
  return 0;
}
