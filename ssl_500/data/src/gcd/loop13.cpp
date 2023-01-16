int gcd(long long x, long long y);

int main(void) {

	long long a,b;
	cin >> a >> b;

	cout << gcd(a, b) << endl;

	return 0;
}

int gcd(long long x, long long y) {

	if (x < y) {
		long long tmp = y;
		y = x;
		x = tmp;
	}

	while (y > 0) {
		long long r = x % y;
		x = y;
		y = r;
	}

	return x;
}
