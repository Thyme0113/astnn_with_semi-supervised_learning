int gcd(int a, int b) {return a > b ? gcd(b, a) : a == 0 ? b : gcd(b % a, a);}

int main()
{
  int a, b; cin >> a >> b;
  cout << gcd(a, b) << endl;
}

