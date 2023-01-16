int gcd(int x, int y){
  if(x == 0){
    return y;
  }else{
    return gcd(y % x, x);
  }
}

int main(int argc,char* argv[]){
  int a, b;
  
  cin >> a >> b;

  cout << gcd(a, b) << endl;

  return 0;  
}
