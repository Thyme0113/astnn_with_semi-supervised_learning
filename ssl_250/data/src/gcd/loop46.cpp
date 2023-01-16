int main(){
	int a,b;
	int x,y;
	int tmp;
	cin >> a >> b;
	x = max(a,b);
	y = min(a,b);
	while(1){
		if(y == 0) break;
		tmp = y;
		y = x%y;
		x = tmp;
	}
	cout << x << endl;
	return 0;
}
