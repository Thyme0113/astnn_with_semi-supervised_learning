long long factorial(int a)
{
    long long ret = 1;
    while(a > 0)
        ret *= a--;
    return ret;
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;
}
