#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int string_size; char *string2; int a,b,c;
	//printf("enter the size of the string - ");
	//scanf("%u",&string_size);
    string_size = 8;
	char *string1 = (char*)malloc(string_size * sizeof(char));
	string1 = fgets(string1,string_size,example.txt);
	*(string1 + 5) = '8'; 
	string2=string1;
	a=10;
	b=20;
	c=a*b;
	printf("value of c is %d\n",c);
	printf("string1 is %s",string1);
	printf("\nstring 2 is %s\n\n",string2);
	free(string1);
	free(string2);
} 
