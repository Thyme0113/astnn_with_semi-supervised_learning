int gcd(int a,int b){return b?gcd(b,a%b):a;};

signed main() {
	cin.tie(0);
	cout.tie(0);
	sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	cout << gcd(n, m) << endl;
	return 0;
}
