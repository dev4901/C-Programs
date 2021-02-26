#include<stdio.h>

int main()
{
	char str[8];
	int i,j;
	gets(str);
	//puts(str);
	for(i=0;i<7;i++)
	{
		printf("%.2d \n",str[i]);
		
	}		
} 
