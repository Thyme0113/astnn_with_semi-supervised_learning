long long  g_f[50];
long long  fib(int n)
{
	if (n == 0 || n == 1)
		return 1;

	if (g_f[n] != 0)
		return g_f[n];

	g_f[n] = fib(n - 1) + fib(n - 2);
	return g_f[n];
}

int main()
{
	int n;
	long long sum = 0;
	scanf("%d", &n);
	sum = fib(n);
	printf("%lld\n", sum);
	return 0;
}
