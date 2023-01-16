int gcd( int x, int y ){
	if( y==0 )	return x;
	return gcd(y,x%y);
}

int main(){
	int x, y;
	cin >> x >> y;
	cout << gcd((x>y?x:y),(x>y?y:x)) << endl;
	return 0;
}
