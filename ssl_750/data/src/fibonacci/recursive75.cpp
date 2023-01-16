int dp[45];

int fib(int n) {
	if(dp[n] >= 0) return dp[n];
	else return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	return 0;
}
