int d;
int dd[50];
int fib(int a){
	if(a==0||a==1)return dd[a]=1;
	if(dd[a])return dd[a];
	return dd[a]=fib(a-1)+fib(a-2);
}

int main() {
int c;
cin>>c;

cout<<fib(c)<<endl;
	return 0;
}
