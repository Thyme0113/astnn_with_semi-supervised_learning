int main() {
    int n;
    cin >> n;
    int fib[50];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2;i < 50; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout << fib[n] << endl;
    return 0;
}
