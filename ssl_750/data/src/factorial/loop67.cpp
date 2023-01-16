int main(){
    int n;
	  cin >> n;
    int x = 1;
    for(int i=1; i<n+1; ++i){
		x = x*i;
    }
    cout << x << endl;
	return 0;
}
