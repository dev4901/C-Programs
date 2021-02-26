#include<stdio.h>
#include<conio.h>

int main()
{
	char str[20],*string1;
	printf("enter str - ");
	scanf("%s",str);
	string1=&str[0];
	//string1 = "fslkfhslk";
	printf("\nstring1 is %s",string1);
} 
