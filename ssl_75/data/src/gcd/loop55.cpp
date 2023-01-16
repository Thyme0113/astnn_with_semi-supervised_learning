int x[1100];
int main()
{
    int n; int m;
    cin >> n >> m;
    if (n < m) {
        swap(n, m);
   }
    int amari = n % m;
    while (amari != 0) {
        n = m;
        m = amari;
        amari = n % m;
    }
    cout << m << endl;
}
