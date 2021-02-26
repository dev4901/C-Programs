#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void cpystring(char *s1, char *s2);

int main(int argc, char const *argv[])
{
	char *s1,*s2;
	s1 = "abcd";
	s2 = (char*)malloc(6*sizeof(char));
	strcpy(s2,s1);
	printf("s2 is %s",s2);
	return 0;
}