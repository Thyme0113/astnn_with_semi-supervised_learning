int F[100];
int fib(int n){
    if(n==0 || n==1){
        return F[n]=1;
    }
    if(F[n]!=-1){
        return F[n];
    }
    return F[n]=fib(n-2)+fib(n-1);
}
int main() {
	int n;
	cin>>n;
	int ans;
    memset(F, -1, sizeof(F));
	ans=fib(n);
	cout<<ans<<'\n';
	return 0;
}
