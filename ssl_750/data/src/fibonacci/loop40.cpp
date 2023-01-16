int main() {
	long long Fib[45];
	Fib[0] = 1;
	Fib[1] = 1;
	for (int i = 2; i < 45; i++) {
		Fib[i] = Fib[i- 2] + Fib[i- 1];
	}
	int N;
	cin >> N;
	cout << Fib[N] << endl;
}

