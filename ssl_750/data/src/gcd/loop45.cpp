int main(){
    int x, y;
    while(cin >> x >> y){
        if(x < y){
            int temp = x;
            x = y;
            y = temp;
        }
        while(y != 0){
            int a, b;
            a = y;
            b = x % y;
            x = a;
            y = b;
        }
        cout << x << endl;
    }
}
