long factorial(long n) {
	if(n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int main() {
	long n;
	
	scanf("%d", &n);

	printf("%ld\n", factorial(n));

	return 0;
}
