long long int GCD(long long int x, long long int y){
    if(x>y){
        long long int swap = x;
        x = y;
        y = swap;
    }
    while(true){
        if(y%x==0){
            return x;
        }else{
            long long int amari = y%x;
            y = x;
            x = amari;
        }
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    int ans = GCD(x, y);

    cout << ans << endl;
    return 0;
}
 
 

