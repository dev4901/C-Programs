#include<stdio.h>

void func();
int var = 8;

int main()
{
		while(var--)
		{
			func();
		}
} 

void func()
{
	static int i=5;
	i++;
	printf("the value of var is %d and that of i is %d\n",var,i);
}
