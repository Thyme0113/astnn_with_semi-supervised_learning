long long int fact(int n){
    if(n==1){
        return 1;
	}
    long long int res=n;
    res*=fact(n-1);
    return res;
}
int main(){
	int n;cin>>n;
	cout<<fact(n)<<endl;
	return 0;
}

