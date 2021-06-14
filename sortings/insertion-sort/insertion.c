#include<stdio.h>

int main()
{
	int a[7],i,j;
	printf("enter the values of array - \n"); //enter 7 unsorted numbers
	for(i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
	}
	
	//method 1 - my method
	/*for (int i = 1; i < 7; i++)
	{
		int key = a[i];
		j=i-1;
		while(a[j]>key && j>=0)
		{
			a[j+1] = a[j]; a[j] = key;
			j--;
		}
	}*/
    
    /* method 2 - book method
    for (int i = 1; i < 7; i++)
	{
		int key = a[i];
		j=i-1;
		while(a[j]>key && j>=0)
		{
			a[j+1] = a[j]; 
			j--;
		}
		a[j+1] = key;
	}*/
    
    //for descending order
    for (int i = 1; i < 7; i++)
	{
		int key = a[i];
		j=i-1;
		while(a[j]<key && j>=0)
		{
			a[j+1] = a[j]; 
			j--;
		}
		a[j+1] = key;
	}
    
	printf("\n");
	for(i=0;i<7;i++)
	{printf("%d , ",a[i]);}
	printf("\n\n");
}
