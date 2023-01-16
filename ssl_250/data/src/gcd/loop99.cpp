int main(){
  int x,y,z;
  cin>>x>>y;
  if(x<y)swap(x,y);
  while(1){
    z=x%y;
    if(z==0)break;
    x=y,y=z;
  }cout<<y<<endl;
  return 0;
}
