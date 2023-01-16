int search(int a,int b){
    if(a%b==0){return b;}
    else{return search(b,a%b);}
}


int main(){
    int x,y;
    cin>>x>>y;
    int c=search(x,y);
    cout<<c<<endl;
    
    return 0;
}

