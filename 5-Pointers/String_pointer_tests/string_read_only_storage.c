#include<stdio.h>

int main()
{
	char *str;
	str="abcdef";
	//*(str+1) = '2'; //here this will not run properly and undefined behavious 
						//will be shown by the compiler as this is stored in a read only segment of the memory
	printf("str now is %s",str);
}
