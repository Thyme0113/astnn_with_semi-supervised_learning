int num[21]={0};
 
long long int kai(int n){
if(num[n]!=0)return num[n];
else{
num[n]=n*kai(n-1);
return num[n];
}
}
 
int main(){
int n;
num[0]=num[1]=1;
cin>>n;
cout<<kai(n)<<endl;
}
 
