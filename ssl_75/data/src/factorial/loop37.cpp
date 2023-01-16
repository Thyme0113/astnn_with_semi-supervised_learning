signed main(void)
{
	int n;
	cin >> n;
	int sum = 1;
	for (int i = 1; i < n+1; ++i) {
		sum *= i;
	}
	cout << sum << endl;
	return 0;
}
