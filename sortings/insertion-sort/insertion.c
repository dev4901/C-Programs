#include<stdio.h>

int main()
{
	int a[7],i,j;
	printf("enter the values of array - \n"); //enter 6 random values for array 
	for(i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 1; i < 7; i++)
	{
		int key = a[i];
		j=i-1;
		while(a[j]>key && j>=0)
		{
			a[j+1] = a[j]; a[j] = key;
			j--;
		}
	}

	printf("\n");
	for(i=0;i<7;i++)
	{printf("%d , ",a[i]);}
	printf("\n\n");
}
