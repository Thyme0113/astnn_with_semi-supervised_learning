int gcd(int a,int b){
if(a==0)return b;
else gcd(b%a,a);
}

int main(){
int a,b;
cin>>a>>b;
cout<<gcd(a,b)<<endl;

return 0;
}

