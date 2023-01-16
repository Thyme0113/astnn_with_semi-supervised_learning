int memo[45];

int fib(int n) {
	if (n <= 1)
		return 1;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = fib(n-1) + fib(n-2);
}

int main() {
	int n;
	cin >> n;
	fill_n(memo, 45, 0);
	cout << fib(n) << endl;
	return 0;
}
