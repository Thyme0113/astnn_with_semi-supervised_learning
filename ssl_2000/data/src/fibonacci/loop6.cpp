int F[45];
int Fibonamake (int n) {
	int t;
	F[0]=F[1]=1;
		for(t=2;t<=n;t++){
		F[t]=F[t-1]+F[t-2];
		}
		return 0; 
	}
	
int main(){
	int n;
	

	Fibonamake(45);
	while(scanf("%d",&n)!=EOF){
		

	printf("%d\n",F[n]);
	}
	return 0;

}
	

