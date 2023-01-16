int g(int a,int b){return b?g(b,a%b):a;}
main(){
  int x,y;
  cin>>x>>y;
  cout<<g(x,y)<<endl;
}
