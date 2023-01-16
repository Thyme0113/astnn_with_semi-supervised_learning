int S[50];
int fib(int N){
    if(N==0||N==1) return S[N]=1;
    if(S[N]!=0) return S[N];
    return S[N]=fib(N-1)+fib(N-2);
}

int main(){

    int N;
    cin>>N;
    cout<<fib(N)<<endl;
}

