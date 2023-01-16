int main() {
	int n,i;
	long long int a = 1;
	cin >> n;
	for (i = 1; i <= n; i++) {
		a *= i;
	}
	cout << a << endl;
	return 0;
}
