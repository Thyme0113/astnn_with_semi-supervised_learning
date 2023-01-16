int dp[44];
int dpf[44] = { 0 };

int fib(int n){
	if(n == 0 || n == 1) return dp[n] = 1;
	if(dpf[n] == 1) return dp[n];
	dpf[n] = 1;
	return dp[n] = fib(n-1)+fib(n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	return 0;
}
