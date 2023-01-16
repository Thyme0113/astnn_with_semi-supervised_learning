int main()
{
	int n;
	int a[45] = { 1,1 };
	sync_with_stdio(false);

	cin >> n;

	for (int i = 2; i < n+1; ++i)
	{
		a[i] = a[i - 1] + a[i - 2];
	}

	cout << a[n] << endl;

	return 0;

}
