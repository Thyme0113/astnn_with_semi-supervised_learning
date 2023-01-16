int main() {
    int a,b,t;
    cin>>a>>b;
    
    while (b) {
        t = a;
        a = b;
        b = t % b;
    }

    if (a < 0) cout << -a;
    else cout << a;
         
    cout<<endl;
 
    return 0;
}
