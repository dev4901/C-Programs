#include<stdio.h>
#include<conio.h>
int main()
{
	int *ptr,code;
	ptr=&code; // here pointer initialization is done
	//*p=66; // value assigned
	*ptr=NULL;
	printf("code is %d",*ptr);
} 
