int gcd(int a, int b) {
	int c = a%b;
	if (c == 0) return b;
	return gcd(b, c);
}
int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d\n", gcd(x, y));
}
