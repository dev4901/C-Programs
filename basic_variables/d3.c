#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,c,d,*ptr;
	scanf("%d",&b);
	ptr=(int*)malloc(b*sizeof(int));
	for(a=0;a<b;a++)
	{
		scanf("%d",ptr+a);
	}
	printf("\n\n");
	printf("%d\n\n",*(ptr+2));
	*(ptr+2) = 4;
	for(a=0;a<b;a++)
	{
		printf("%d",*(ptr+a));
	}
	printf("\n%d",*(ptr+0));
	*(ptr+0)=*(ptr+3);
	c=*(ptr+3);
	printf("\n%d %d",*(ptr+0),c);
} 

