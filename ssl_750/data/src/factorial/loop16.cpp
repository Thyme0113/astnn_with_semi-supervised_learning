int main(){
long long a,s=1;
cin>>a;
for(int i;i<a+1;i++) {
    if(i)s*=i;
}
cout<<s<<endl;
}