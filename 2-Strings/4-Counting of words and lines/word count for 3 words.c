#include<stdio.h>
#include<string.h>

int main()
{
		char a[10];
		int b;
		gets(a);
		b=strlen(a);
		printf("%d\n",b); 
		printf("%c",a[9]);
		if(a[3]==' ')
			printf("there is space\n");
		if(a[9]=='\0' )
			printf("ok");
} 
