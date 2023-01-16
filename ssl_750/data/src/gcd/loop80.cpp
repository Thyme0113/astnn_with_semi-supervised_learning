int main() {
  int x,y;
  cin>>x>>y;
  while(max(x,y)%min(x,y)!=0){
    if(x>y){
      x=x%y;
    }
    else{
      y=y%x;
    }
  }
  cout<<min(x,y)<<endl;
  return 0;
}

