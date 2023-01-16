int f(int x){
    if(x == 1) return 1;
    return x*f(x-1);
}

int main(){
    long long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
