long long factorial (long n){
	
	if (n == 0LL || n == 1LL){
		return 1LL;
	}
	return n*factorial(n-1);
}

int main()
{
	long long res;
	long long n;
	cin >> n;
	res = factorial(n);
	cout << res << endl;
		
	return 0;
}
