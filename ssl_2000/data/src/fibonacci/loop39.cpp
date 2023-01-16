int main() {
    int f[50];
    f[0]=f[1]=1;
    int n;
    cin>>n;
    for(int i=0;i<n+1;i++) {
        if(i>1) f[i]=f[i-1]+f[i-2];
    }
    
    cout<<f[n]<<endl;
    return 0;
}
