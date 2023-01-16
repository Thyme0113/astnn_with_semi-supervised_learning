int numbar_A, numbar_B;
int a, b;

int main(){
	scanf("%d %d", &numbar_A, &numbar_B);
	if(numbar_A < numbar_B)
		swap(numbar_A, numbar_B);
	a = numbar_A;
	b = numbar_B;
	while(a % b != 0){
		a = a % b;
		swap(a, b);
	}
	printf("%d\n", b);
	return 0;
}
