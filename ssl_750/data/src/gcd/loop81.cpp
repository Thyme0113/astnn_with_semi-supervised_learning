int main()
{
	int a, b;
	int x, y;
	cin >> x >> y;
	a = max(x, y);
	b = min(x, y);
	while (b)
	{
		int k = b;
		b = a%b;
		a = k;
	}
	cout << a << endl;
}
