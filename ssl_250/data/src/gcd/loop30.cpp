int gcd(int x, int y){
    while(1){
        int r = x % y;
        if(r == 0) return y;
        x = y;
        y = r;
    }
}

int main(void){
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;

    return 0;
}
