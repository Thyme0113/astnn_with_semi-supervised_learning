int n;
int ans=1;

int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		ans*=i;
	}
	cout<<ans<<endl;
}
