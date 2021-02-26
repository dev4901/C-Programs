//exchange string values in different arrays and positions
#include<stdio.h>
#include<string.h>

int main()
{
	char str[2][6] = {"good","abcd"} ;
	char sub[3][6]; int i;
	/*int i,j;
	printf("enter row numbers you want to exchange - ");
	scanf("%d %d", &i)
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			
		}
	}	*/
	
	strcpy(str[0],str[1]);
	puts(str[1]);
	for(i=0;i<2;i++)
	{
	puts(str[i]);
	}
} 
