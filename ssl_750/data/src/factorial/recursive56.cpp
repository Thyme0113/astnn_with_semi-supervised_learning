int factor(int n) {
	return n == 1 ? 1 : n * factor(n - 1);
}

int main() {
	int n; cin >> n;
	cout << factor(n) << endl;
	return 0;
}
