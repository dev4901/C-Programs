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
	
	printf("original series\n");
	for(a=0;a<b;a++)
	{
		printf("%d ",*(ptr+a));
	}
	printf("\n");
	
/*	c = *(ptr + 1);
    *(ptr + 1) = *(ptr + 5);
    *(ptr + 5) =  c;*/
	for(a = 0 ; a < b; a++)
    {
        d= b - 1 - a;
        c = *(ptr + a);
        *(ptr + a) = *(ptr + d);
        *(ptr + a) =  c;
    }   
	
	printf("\n\nnew series\n");
	for(a = 0; a < b; a++)
        printf("%d ", *(ptr + a));
} 

