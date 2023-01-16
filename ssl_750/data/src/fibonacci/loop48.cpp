int F[100];

int main(){
  int n;
  F[0] = 1;
  F[1] = 1;
  for (int i = 2; i < 45 ; i++) {
    F[i] = F[i-2] + F[i-1];
  }
  cin >> n;
  cout << F[n]<<endl;

}
