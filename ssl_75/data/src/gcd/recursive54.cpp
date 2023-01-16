int gcd (int x, int y )
{
	if (x % y == 0 ) return y;

	if (x < y ) swap (x, y );

	return gcd (y, x % y );
}

int main()
{
	int a, b;
	scanf ("%d %d", &a, &b );
	int res = gcd (a, b );
	printf ("%d\n", res );
		
	return 0;
}
