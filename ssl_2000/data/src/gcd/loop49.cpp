int gcd(int a, int b){
    int t;
    if( a < b ){
        t = a;
        a = b;
        b = t;
    }
    while(1){
        t = a%b;
        if(t == 0) return b;
        a = b; b = t; 
    }
    return -1;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
