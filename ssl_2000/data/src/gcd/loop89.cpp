int main(){
	int a;
	int b;
	cin >> a;
	cin >> b;
	int c;
	if ( a*b != 0 ) {
		while(true) {
			if ( a>b ) {
				c=a;
				a=b;
				b=c;
			}
			if ( a==0 ) break;
			b=b%a;
		}
	}else {
		b=0;
	}
	cout << b << endl;
	return 0;
}
