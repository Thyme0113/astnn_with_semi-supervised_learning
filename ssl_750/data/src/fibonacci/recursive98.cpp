int dp[45] = {0};
int fib(int n) {
	if (dp[n] != 0) return dp[n];
	if (n == 0 || n == 1) return 1;
	return dp[n] = fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int ans = fib(n);
	cout << ans << endl;
	return 0;
}
