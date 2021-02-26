#include<stdio.h>
#include<string.h>

void checkarr(int arr[], int size);

int main()
{
	int a;
	int array[4]={2,5,6,7};
	a=0;
	//check(a);
	printf("\n//before function called//\n");
	for(a=0;a<4;a++)
	{
		printf("%d , ", array[a]);
	}
	printf("\n\n//after functioncalled//\n");
	checkarr(array,4);
	for(a=0;a<4;a++)
	{
		printf("%d , ",array[a]);
	}
} 



void checkarr(int arr[], int size)
{
	int t=0;
	while (t<size)
	{
	arr[t] =  0 ;
	t++;
	}
}





