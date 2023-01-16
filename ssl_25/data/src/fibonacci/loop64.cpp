int main(){
	
	int n[47];
	n[0]=0;
	n[1]=1;n[2]=2;

	for(int i=3;i<=45;i++)
		n[i]=n[i-1]+n[i-2];
	int x;
	cin>>x;
	cout<<n[x]<<endl;
	return 0;
}
