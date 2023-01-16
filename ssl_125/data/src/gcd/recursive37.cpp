long long x,y;

long long gcd(long long n, long long m){
	if(n%m == 0) return m;
	else return gcd(m,n%m);
}

int main(){
	cin >> x >> y;
	cout << gcd(x,y) << endl;
}
