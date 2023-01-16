int greatestCommonDivisor(int a, int b);

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	
	int n = greatestCommonDivisor(a, b);
	
	printf("%d\n", n);
	
	return 0;
}

int greatestCommonDivisor(int a, int b){
	while(a != b){
		if (a > b) a %= b;
		else b %= a;
		
		if(a % b == 0 || b % a == 0) break;
	}
	return a < b ? a : b;
}
