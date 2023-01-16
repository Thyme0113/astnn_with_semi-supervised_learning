int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

signed main(){
    int x,y;
    cin>>x>>y;
    cout<<gcd(x,y)<<endl;
    return 0;
}
