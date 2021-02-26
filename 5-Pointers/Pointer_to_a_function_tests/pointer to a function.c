#include<stdio.h>
#include<conio.h>

//int (*ptr)();
int large(int *x,int *y);
int sum(int (*ptr)(),int *a,int *b);

int main()
{
	int a,b,r,c,suma;
	a=25;
	b=45;
	c=20;
	//ptr=large;
	r=large(&a,&b); // parenthesis outside pointer name are mandatory
	suma = sum(large,&c,&b); 
	printf("suma is %d",suma);
} 

int large(int *x,int *y)
{
	if(*x>*y)
		return *x;
	else
		return *y;
}

int sum(int(*ptr)(),int *a,int *b)
{
	int sum,v;
	v=(*ptr)(a,b);
	sum= v + *a + *b;
	return(sum);
}
