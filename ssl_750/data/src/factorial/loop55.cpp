int main() {
	int n;
	long long d=1;
	cin >> n;
	for (int i = 0; i < n; i++){
		d *= (i + 1);
	}
	cout << d << endl;
	
}
