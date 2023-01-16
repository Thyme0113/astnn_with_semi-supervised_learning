long long int f(long long int n){
	if(n>0)
	return n*f(n-1);
	else
	return 1;
}

int main(){
	long long int n;
	
	cin>>n;
	
	cout<<f(n)<<endl;
}
