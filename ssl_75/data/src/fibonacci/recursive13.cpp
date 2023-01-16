int dp[45] = {};
int fib(int a) {
	if (a == 0 || a == 1) return 1;
	if (dp[a] != 0) return dp[a];
	return dp[a] = fib(a - 1) + fib(a - 2);
}
int main() {
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", fib(n));
}
