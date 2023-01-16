long GCD(unsigned long a,unsigned long b){
	if(b==0) return a;
	return GCD(b,a%b);
}

int main(void){

	unsigned long x,y;

	cin>>x>>y;

	cout<<GCD(x,y)<<endl;

	return 0;
}
