int gcd(int a, int b){
    if(b == 0)  return a;
    else    return gcd(b, a%b);
}
int main(void){
    int a, b, c;
    cin >> a >> b;
    if(a < b){
        c = a;
        a = b;
        b = c;
    }
    
    cout << gcd(a,b) << endl;
    return 0;
}

