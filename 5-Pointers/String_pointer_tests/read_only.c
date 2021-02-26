#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *str;
	str="abcdef";
	//*(str+1) = '2'; this here is invalid.
	printf("\nstr now is %s\n",str);
}
