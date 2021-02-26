#include<stdio.h>
#include<string.h>

int main()
{
	char *email,*local;
	email="abcd.efggmail.com";
	local=strstr(email,"@gmail.com");
	printf("after strstr local is %s",local);
}
