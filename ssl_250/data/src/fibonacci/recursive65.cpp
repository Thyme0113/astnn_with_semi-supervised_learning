long long int f[50];

long long int fib(int n){
    if(f[n]!=0);
    else if(n==0||n==1){
        f[n]=1;
    }else{
        f[n]=fib(n-1)+fib(n-2);
    }
    return f[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    
    return 0;
}
