int main(){
    int n;
	cin >> n;
    long long int x = 1;
    for(int i=0; i<n; ++i){
		x = x*(i+1);
    }
    cout << x << endl;
	return 0;
}
