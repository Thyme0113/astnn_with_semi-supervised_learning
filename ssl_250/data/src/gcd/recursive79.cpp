int gcd(int x,int y){
  if(x%y ==0)
    return y;
  else
    return gcd(y,(x%y));
}
int main()
{
  int a,b;
  cin >>a>>b;
  if(a <b)
    swap(a,b);
  cout <<gcd(a,b)<<endl;;
  return 0;
}
