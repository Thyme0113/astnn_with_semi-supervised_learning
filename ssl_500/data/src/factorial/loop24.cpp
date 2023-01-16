int main(void)
{
    int n;
    cin >> n;

    long long unsigned int result = 1;
    for ( ; n > 0; n--) {
        result *= n;
    }

    cout << result << endl;
    return 0;
}
