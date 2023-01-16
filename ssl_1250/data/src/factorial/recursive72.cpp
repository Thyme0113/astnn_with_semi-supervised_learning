long kaijou(long);
long n;

int main(){
	cin >>n;
	cout << kaijou(n) <<endl;

	return 0;
}

long kaijou(long i){
	if(i == 0){
		return 1;
	} else {
		return i * kaijou(i-1);
	}
}
