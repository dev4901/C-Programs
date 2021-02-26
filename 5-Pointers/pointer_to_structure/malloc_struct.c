#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int* age;
	char* s;
}data;

int main(int argc, char const *argv[])
{
	data *d1;
	d1 = (data*)malloc(2*sizeof(data));
	for(int i=0;i<2;i++)
	{
		(d1+i)->age = malloc(sizeof(int));
		(d1+i)->s = malloc(10*sizeof(char));
		printf("enter age for %d: ",i);
		scanf("%d ",(d1+i)->age);
		printf("enter the string for %d: ",i);
		scanf("%s",(d1+i)->s);
		//fgets((d1+i)->s,10,stdin);
	}
	printf("\n");
	for(int i=0;i<2;i++){printf("age is %d and string is %s\n",*(d1+i)->age, (d1+i)->s);}
	return 0;
}