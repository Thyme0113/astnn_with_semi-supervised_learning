int main(){
  int n,ans=1;
  cin>>n;
  for(long long i=n;i>=1;i--){
    ans*=i;
  }
  cout<<ans<<endl;
  return 0;
}