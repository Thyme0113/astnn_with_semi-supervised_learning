long long func(long long n){
	if(n == 1){
		return 1;
	}else{
		return n*func(n-1);
	}
}

int main(){

	long long n;
	scanf("%lld",&n);
	printf("%lld\n",func(n));

    return 0;
}