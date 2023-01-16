int main(void)
{
	long long n;
	cin >> n;
	long long x = 1;
	while(n)
	{
		x *= n;
		n--;
	}
	cout << x << endl;
	return 0;
}
