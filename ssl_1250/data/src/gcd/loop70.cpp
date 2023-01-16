main(){
  
  int a,b,temp,r;
  
    scanf("%d %d",&a,&b);
    if(a<b){
      temp=a;
      a=b; 
      b=temp;
    }
    
      
  while((r=a%b)!=0){
    a=b;
    b=r;
  }
  printf("%d\n",b);
}
