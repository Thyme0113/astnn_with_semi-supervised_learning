void solve()
{
	int fibo[50];
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i = 2; i <= 44; ++i)
	{
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	int n;
	cin >> n;
	cout << fibo[n] << endl;
}

int main()
{
	solve();
	return(0);
}
