#include<stdio.h>
#include<stdlib.h>

void copy(char *s1,char *s2);

int main()
{
	char *string1,*string2;		
	string1 = "adadfsdf";
	string2=string1; // assigning address of 1st element of string1 to string2
	//copy(string1,string2);
	printf("string 1 is %s\n",string1);
	printf("string 2 is %s\n\n",string2);
} 

void copy(char *s1,char *s2)
{
	while(*s1=='\0');
	{
		*s1=*s2;
		s1++;s2++;
	}
	*s2='\0';
}

