int main() {
	int fib[50];
	fib[0] = 1;
	fib[1] = 1;
	int n; cin >> n;
	for (int i = 2; i < n + 1; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	cout << fib[n] << endl;
}
