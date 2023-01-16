long long func(int);
long long fib[45];
int main(void)
{
	int n,i;
	long long x;
	scanf("%d",&n);
	fib[0]=1;	fib[1]=1;
	for(i=2;i<=n;i++)	fib[i]=0;
	x=func(n);
	printf("%lld\n",x);
	return 0;
}
long long func(int nn)
{
	long long x;
	if(nn<2)	return fib[nn];
	else {
		if(fib[nn]==0)	{
			x=func(nn-1)+func(nn-2);
			fib[nn]=x;
			return x;
		}
		else return fib[nn];
	}
}	
