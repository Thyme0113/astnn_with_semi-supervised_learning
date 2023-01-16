int fact(int n)
{
	return n<=1 ? 1 : n*fact(n-1);
}

int main()
{
	int n;
	scanf("%lld",&n);
	cout << fact(n) << endl;
}
