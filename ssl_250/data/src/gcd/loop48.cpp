int gcd(int x, int y){
    if(x < y){
        int temp = x;
        x = y;
        y = temp;
    }

    while(y > 0){
        int r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main(void){

    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
}
