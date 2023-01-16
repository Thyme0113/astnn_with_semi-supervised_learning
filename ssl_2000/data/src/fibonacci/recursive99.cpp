int f[45];

int fib(int n)
{
	if(n==0 || n==1) return f[n]=1;
	if(f[n]!=-1) return f[n];
	return f[n]=fib(n-1)+fib(n-2);;
}

int main()
{
	int n;
	
	cin >> n;
	for(int i=0;i<=44;i++) f[i]=-1;
	cout << fib(n) << endl;
	return 0;
}
