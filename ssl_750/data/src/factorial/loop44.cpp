int main(){
	unsigned long long int a=1;
	int i,n;
	cin>>n;
	for(i=n;i>0;i--){
		a*=i;
	}
	cout<<a<<endl;
	return 0;
}
