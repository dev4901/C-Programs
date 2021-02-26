#include<stdio.h>
#include<string.h>

int main()
{
	int a,*b,d;
	char *ptr, time[12],*c;
	scanf("%s",time);
	ptr=time;
	a=atoi(ptr);
	d=34;
	b=(int *)&time;
	c=(char *)&d;
	printf("\n a is %d\nb is %d\nd is %s",a,*b,c);
} 

