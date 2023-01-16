int main()
{
  int x,y,z;

  cin>>x>>y;
  while(x%y!=0){
    z=x%y;
    x=y;
    y=z;
  }
  cout<<y<<endl;
  return 0;
}
