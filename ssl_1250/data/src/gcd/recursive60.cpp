int gcd(int a, int b){
    if(!b)return a;
    return gcd(b,a%b);
}

int main(){
    int a,b;

    cin >> a >> b;
    if(a<b){
        int swap = a;
        a = b;
        b = swap;
    }
    cout << gcd(a,b) << endl;
    return 0;
}
