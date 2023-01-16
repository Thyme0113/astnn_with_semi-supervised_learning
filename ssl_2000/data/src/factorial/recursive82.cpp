long long fact( int n )
{
	if( n == 1 ) return 1;
	else return n * fact( n - 1 );
}

int main()
{
	int x;
	cin >> x;
	cout << fact( x ) << endl;

 	return 0;
}
