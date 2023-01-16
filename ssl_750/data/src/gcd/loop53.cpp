int main() {
	long long n, x, y; cin >> x >> y;
	while (true) {
		if (x > y) {
			x = x % y;
		}
		else if (x < y) {
			y = y % x;
		}
		if (x == 0 || x == y) {
			cout << y << endl; cin >> n;
			return 0;
		}
		if (y == 0) {
			cout << x << endl; cin >> n;
			return 0;
		}
	}
	cin >> n;
}
