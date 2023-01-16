int main(){
  int a, b;
  cin >> a >> b;
  while (1){
    swap(a, b);
    b = b % a;
    if (b == 0){
      break;
    }
  }
  cout << a << endl;
}
