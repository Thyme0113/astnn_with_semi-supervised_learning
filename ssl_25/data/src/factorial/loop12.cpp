int main()
{
  int n,i;
  cin >> n;
  long long ans=1;
  for(i=1;i<=n;i++)
  ans*=i;
  cout << ans << endl;
}