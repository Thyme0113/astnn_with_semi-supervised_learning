int main(){
	int i,n;
	long long int res = 1;
	scanf("%d",&n);
	for(i = 1;i <= n;i++) res *= i;
	printf("%lld\n",res);
	return 0;
}
