#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int string_size; char *string2; int a,b,c; FILE *input;
	//printf("enter the size of the string - ");
	//scanf("%u",&string_size);
	input = fopen("example.txt","r");
	char *string1 = (char*)malloc(13 * sizeof(char));
	fgets(string1,8,input);
	//*(string1 + 5) = '8'; 
	//string2=string1;
	a=10;
	b=20;
	c=a*b;
	printf("value of c is %d\n",c);
	//fclose(input);
	if(string1==NULL)
	{
		printf("nothing is stored in string 1 :( \n");
	}
	else
	{printf("\nstring1 is %s \n",string1);}
	free(string1);
	fclose(input);
	//printf("string1 is %s",string1);
	//printf("\nstring 2 is %s\n\n",string2);
} 
