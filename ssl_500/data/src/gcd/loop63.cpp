int main() {
	int a, b;
	int MAX, MIN;
	int kari;
	cin >> a >> b;
	MAX = max(a, b);
	MIN = min(a, b);
	while (1) {
		if (MAX % MIN == 0) {
			break;
		} else {
			kari = MAX % MIN;
			MAX = max(MIN, kari);
			MIN = min(MIN, kari);
		}
	}
	cout << MIN << endl;
	return 0;
}
