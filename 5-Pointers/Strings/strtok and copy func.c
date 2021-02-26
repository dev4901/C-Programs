#include<stdio.h>
#include<string.h>

void copy(char *s1,char *s2);

int main()
{
	char *s1,in[12],*s2,out[12];
	scanf("%s",in);
	s1=in;
	s2=out;
	//copy(in,s2);
	strcpy(s2,s1);
	printf("s1 is %s\ns2 is %s",s1,s2);
}

void copy(char *s1, char *s2)
{
	while((*s1++=*s2++)!='\0');
}
