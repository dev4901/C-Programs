#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	char *s1=malloc(21*sizeof(char));
	FILE *fpt,*fstore;
	fstore = fopen("exit.txt","w+");
	fpt = fopen("example.txt","r");
	s1=fgets(s1,19,fpt);
	while(s1)
	{
		int get=strcmp(s1,"Lessthan50K");
		if(get<0)
		{
			fprintf(fstore,"%s",s1);
		}
		s1=fgets(s1,19,fpt);
	}
	
	/*
	if(get==0)
		printf("both are same\n");
	else
		printf("both are different\n");
	*/
	return 0;
}