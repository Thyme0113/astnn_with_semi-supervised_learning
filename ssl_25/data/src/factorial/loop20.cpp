int main() {
    long long n;
    cin >> n;
    long long res = 1;
    for (int i = 1; i <= n; ++i) res *= i;
    cout << res << endl;
    return 0;
}