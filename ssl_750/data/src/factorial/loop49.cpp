int main() {
	int n;
	long long s = 1;
	cin >> n;
	while (n)s *= n--;
	cout << s << endl;
	return 0;
}
