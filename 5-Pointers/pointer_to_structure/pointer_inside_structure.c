#include <stdio.h>
#include <stdlib.h>

struct abc
{
	int *x;
	char *str;
};

typedef struct abc abc;

int main()
{
	struct abc *myvar;
	myvar->x = (int *)calloc(1, sizeof(int));
	myvar->str = (char *)malloc(5 * sizeof(char));
	myvar->x = 25;
	printf("enter the string value - ");
	scanf("%s", (*myvar).str);
	printf("string is %s \ninteger is %d\n\n", (*myvar).str, (*myvar).x);
}
