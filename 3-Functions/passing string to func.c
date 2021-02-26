//Aim - to test passing strings to a function.
//working - This generates a pyramid of the string that is entered in the input 
//user - enter any string of max length 30 characters	 
#include<stdio.h>

void str(char srt[]);

int main()
{
	char string[30];
	printf("enter the string whose pyramid you want to generate - \n");
	gets(string);
	str(string);	
} 

void str(char str[])
{
	int i,j,k;
	printf("\n");
	printf("////Function execution starts////\n\n");
	for(i=0;str[i]!='\0';i++)
	{
		for(j=0;j<=i;j++)
		{
		printf("%c",str[j]);
		}
		printf("\n");
	}
	for(k=(i-2);k>=0;k--)
	{
		for(j=0;j<=k;j++)
		{
		printf("%c",str[j]);
		}
		printf("\n");
	}
	printf("\n\n////Function execution ended successfully////\n");
}
