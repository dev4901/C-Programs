#include<stdio.h>
#include<conio.h>
int main()
{
	int *p,b,a[3];
	p=a;
	*p=89;
	printf("p+0 = %d and that is %d\n",p,*(p));
	//p=p+1;
	*(p+1)=34;
	printf("p+1 = %d and that is %d\n",p+1,*(p+1));
	//p=p+1;
	*(p+2)=23;
	printf("p+2 = %d and that is %d",p+2,*(p+2));
} 
