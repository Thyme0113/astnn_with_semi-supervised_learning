int n;
int ans;

int main(){
	cin>>n;
	ans=1;
	for(int i=0;i<n;++i) {
		ans*=i+1;
	}
	cout<<ans<<endl;
	
	return 0;
}
