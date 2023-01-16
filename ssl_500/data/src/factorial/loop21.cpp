int main(){
  int n;
  long long ans=1;
  cin>>n;
  while(n){
    ans*=n--;
  }
  cout<<ans<<endl;
  return 0;
}
