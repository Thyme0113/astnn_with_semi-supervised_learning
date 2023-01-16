int main(){
  int n;
  while(cin>>n){
    int f = 1;
    do{
      f *= n;
    }while(--n!=0);
    cout << f << endl;
  }
  return 0;
}
