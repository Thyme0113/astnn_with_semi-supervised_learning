int nari(int,int);

int main(){

  int a,b;
  cin >> a >> b;

  cout <<  nari(a,b) << endl;
  return 0;
}

int nari(int a,int b)
{
  int r = a%b;
  while(r>0)
    {
      a=b;
      b=r;
      r=a%b;
    }
  return b;
}
