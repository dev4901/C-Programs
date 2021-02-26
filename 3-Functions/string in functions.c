#include<stdio.h>
#include<string.h>

void string(char str[]);

int main()
{
	char s1[12];
	gets(s1);
	string(s1);
} 

void string(char str[])
{
	int i;
	printf("length of string is %d\n",strlen(str));
	if(str[1]==str[2])
		printf("%c",str[2]);
	else
		printf("not equal because %c and %c",str[1],str[2]);
	for(i=0;i<5;i++)
		printf("%d ",i);
	printf("\n after loop i is %d",i);		
}
