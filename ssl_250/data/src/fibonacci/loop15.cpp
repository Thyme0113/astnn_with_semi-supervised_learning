int main() {
  int N;
  cin>>N;
  int p[N+1];
  p[0]=1,p[1]=1;
  for(int i=2;i<=N;i++){
    p[i]=p[i-1]+p[i-2];
  }
  cout<<p[N]<<endl;
}

