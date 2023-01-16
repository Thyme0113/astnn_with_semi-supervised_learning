int gcd(int x,int y){
  if(y>x){
    int tmp=x;
    x=y;
    y=tmp;
  }
  while(y>0){
    int r=x%y;
    x=y;
    y=r;
  }
  return x;
}
int main()
{
  int x,y;
  cin>>x>>y;
  cout<<gcd(x,y)<<endl;
}

