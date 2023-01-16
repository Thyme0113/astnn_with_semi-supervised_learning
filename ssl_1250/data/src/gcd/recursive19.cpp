int GCD(int x, int y){
    if(x % y == 0) return y;
    GCD(y, x % y);
}

int main(){
    int x, y; cin >> x >> y;
    cout << GCD(x, y)<< endl;
    return 0;
}
   
