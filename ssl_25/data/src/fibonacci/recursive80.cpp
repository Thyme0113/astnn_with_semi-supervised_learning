const int MAX_N = 440;

long memo[MAX_N] = {};

long fibonacci(int n) {
    switch (n) {
        case 0:
        case 1:
            return 1;
        default:
            if (memo[n])
                return memo[n];
            else
                return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}
