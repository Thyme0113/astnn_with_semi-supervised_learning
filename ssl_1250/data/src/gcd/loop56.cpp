int main(void){

  long long a,b,c;
  cin >> a >> b;

  while(1){
    c = a % b;
    if( c == 0 ) break;
    a = b;
    b = c;
  }
  cout << b << endl;

  return 0;
}
