int main(){
	int n;
	cin >> n;
	long long int ans=1;
	for(int i=2; i<=n; i++){
		ans *= i;
	}
	cout << ans << endl;
	return 0;
}