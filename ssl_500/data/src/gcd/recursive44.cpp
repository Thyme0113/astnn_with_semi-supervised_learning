int gcd(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	return gcd(y, x % y);
}

int main() {
	int x = -1;
	int y = -1;

	cin >> x >> y;
	if (x < y) {
		swap(x, y);
	}

	cout << gcd(x, y) << endl;
	return 0;
}
