int F[45] = {};

int fib(int n) {
	if (n == 0 || n == 1) return F[n] = 1;
	if (F[n]) return F[n];
	return F[n] = fib(n - 1) + fib(n - 2);		
}
int main() {
	int n;	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
