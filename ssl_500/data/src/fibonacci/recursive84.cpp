int A[45] = {};
int B[45];

int fib(int n);

int main() {
	
	int n;
	
	while(cin >> n) {
		
		for(int i=0;i<n;i++)
			B[i] = 0;
		
		cout << fib(n) << "\n";
		
	}

	return 0;
}

int fib(int n) {
	
	A[0] == A[1] == 1;
	
	if(n == 0 || n == 1) 
		return 1;
	
	else if(B[n])
		return A[n];
		
	else {
		A[n] = fib(n-1) + fib(n-2);
		B[n] = 1;
		return A[n];
}

}
