int main(){
  int n,a[2]={1,1};
  cin>>n;

  int c=0;
  for(int i=1;i<n;i++)a[c]=a[0]+a[1],c=!c;
  cout << a[!c]<<endl;
  return 0;
}
