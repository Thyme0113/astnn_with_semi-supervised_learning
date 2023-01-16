long long int F[44]={0};
long long int fibonacci(int n){
	if(n==0 || n==1)return F[n] = 1;
	if(F[n]!=0)return F[n];
	return F[n] = fibonacci(n-2) + fibonacci(n-1);

}

int main(){
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
	return 0;
}
