int main(){
	int n,k=1;
	cin>>n;

	for(int i=0;i<n;i++) {
		k*=(i+1);
	}
	cout<<k<<endl;
	return 0;
}
