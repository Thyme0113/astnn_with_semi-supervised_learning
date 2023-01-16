int gcd(int n,int m){
	if(n%m==0)return m;
	return gcd(m,n%m);
}

int x,y;

int main(){
	cin>>x>>y;
	cout<<gcd(x,y)<<endl;
}
