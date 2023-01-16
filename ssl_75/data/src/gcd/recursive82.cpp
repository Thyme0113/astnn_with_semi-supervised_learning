int gcd(int x, int y){
    if(x%y) return gcd( y, x%y);
    else return y;
}

int main(){
    int X,Y;
    cin >> X >> Y;
    cout << gcd(X,Y) << endl;
}
