int main()
{
  int n;
  int ans=1;
  int i;
  cin>>n;

  for(i=n;i>1;i--)
    ans*=i;
  cout<<ans<<endl;

}
