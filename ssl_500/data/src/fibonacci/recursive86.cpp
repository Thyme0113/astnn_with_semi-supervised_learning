int memo[64];
int fib(int n){
	if(n < 2) return 1;
	return memo[n] != -1 ? memo[n] : (memo[n] = fib(n-1) + fib(n-2));
}

int main() {
	memset(memo, -1, 64);
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
