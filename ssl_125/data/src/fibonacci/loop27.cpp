int fib[46];

int main()
{
	memset (fib, 0, sizeof (fib ) );
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 46; i++ ){
		fib[i] = fib[i-1] + fib[i-2];
	}

	sync_with_stdio(0);
	int n; cin >> n;
	printf ("%d\n", fib[n] );
		
	return 0;
}
