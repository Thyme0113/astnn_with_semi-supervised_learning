int gcd(int a,int b){
  if(a%b)return gcd(b,a%b);
  return b;
}

int main(){
  int a,b;
  cin>>a>>b;
  cout<<gcd(a,b)<<endl;
  return 0;
}
