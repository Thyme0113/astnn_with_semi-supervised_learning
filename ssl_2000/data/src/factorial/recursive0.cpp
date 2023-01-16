int factrial(int n) {
  if(n == 1) return 1;
  else return n * factrial(n-1);
}

int main() {
  int n;

  cin >> n;

  cout << factrial(n) << endl;
}
