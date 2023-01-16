int main(){
    int a[55];
    a[0]=a[1]=1;
    for(int i=0 ; i < 50 ; ++i ) {
        a[i+2]=a[i+1]+a[i];
    }
    int n;cin>>n;
    cout<<a[n]<<endl;
    return 0;
}
