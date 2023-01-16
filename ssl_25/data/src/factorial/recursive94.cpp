long long calc(int n){

	if (n == 1)return 1;

	return n*calc(n - 1);

}

int main(){

	int n;
	cin >> n;

	cout << calc(n) << endl;

	return 0;
}
