int GCD(int n, int m)
{
    if (n == 0) return m;
    if (m == 0)   return n;
    if (n > m)
        return GCD(n % m, m);
    else 
        return GCD(m % n, n);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << GCD(n, m) << endl;

}
