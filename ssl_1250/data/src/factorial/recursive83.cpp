int factorial(int n){ return n ? n * factorial(n-1) : 1; }

int main()
{
	long long n;
	cin >> n;
	cout << factorial(n) << endl;
}
