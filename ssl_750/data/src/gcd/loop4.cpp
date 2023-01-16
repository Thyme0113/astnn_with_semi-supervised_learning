int calc_gcd(int a,int b){
  int x=a,y=b,z;
  if(x<y){
    z=x;
    x=y;
    y=z;
  }
  while(y>0){
    z=x%y;
    x=y;
    y=z;
  }
  return x;
}
int main(){
  int a,b;
  cin>>a>>b;
  cout<<calc_gcd(a,b)<<endl;
  return 0;
}
