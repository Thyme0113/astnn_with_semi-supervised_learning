int GCD(int x, int y)
{
	if (x == 0)
	{
		return(y);
	}
	else
	{
		GCD(y % x, x);
	}
}

void solve()
{
	int x, y;
	cin >> x >> y;
	cout << GCD(x, y) << endl;
}

int main()
{
	solve();
	return(0);
}
