int k(int n) {
	if (n <= 1) return 1;
	return n * k(n - 1);
}

int main() { int n; cin >> n; cout << k(n) << endl; return 0; }
