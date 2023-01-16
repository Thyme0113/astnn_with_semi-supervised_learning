int main(void)
{
	int x,y,a,b;
	scanf("%d %d",&x,&y);
	if(x<y)	swap(x,y);
	while(1)	{
		b=x%y;
		if(b==0)	break;
		else {
			x=y;
			y=b;
		}
	}
	printf("%d\n",y);
	return 0;
}
