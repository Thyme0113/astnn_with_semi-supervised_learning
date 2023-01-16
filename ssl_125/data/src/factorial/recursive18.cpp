long long f(int n){
	return (n == 0 ? 1 : n * f(n-1));
}
int main(){
	int n;
	cin >> n;
	cout << f(n) << endl;
}
