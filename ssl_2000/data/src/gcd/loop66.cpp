int main()
{
	unsigned long long a[100] = { 0 }, t = 0;

	cin >> a[0] >> a[1];

	if (a[0] < a[1]) {
		t = a[0];
		a[0] = a[1];
		a[1] = t;
	}

	a[2] = a[0] % a[1];
	int i = 2;

	while (a[i] > 0) {
		a[i + 1] = a[i - 1] % a[i];
		i++;
	}

	cout << a[i - 1] << endl;
		
	return 0;
}
