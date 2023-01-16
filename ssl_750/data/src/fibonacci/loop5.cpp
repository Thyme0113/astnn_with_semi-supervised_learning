const int MAX_N = 44;

int fs[MAX_N + 1];

int main() {
  int n;
  cin >> n;

  fs[0] = fs[1] = 1;

  for (int i = 2; i <= n; i++)
    fs[i] = fs[i - 1] + fs[i - 2];

  printf("%d\n", fs[n]);
  return 0;
}
