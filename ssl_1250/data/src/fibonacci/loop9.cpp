int main(){
  int f[45];
  f[0]=f[1]=1;
  for(int i=2;i<45;i++){
    f[i]=f[i-1]+f[i-2];
  }
  int a;cin>>a;
  cout<<f[a]<<endl;
}
