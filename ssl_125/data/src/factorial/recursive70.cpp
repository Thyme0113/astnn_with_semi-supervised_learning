unsigned long int calc(unsigned long int n)
{
	if(n<=1)
		return 1;
	else
		return n*calc(n-1);
}

int main()
{
	unsigned long int n;
	scanf("%d",&n);
	printf("%lu\n",calc(n));
	return 0;
}
