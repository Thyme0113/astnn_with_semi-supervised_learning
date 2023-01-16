long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

int main(){
	cin.sync_with_stdio(false);
	long long a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}
