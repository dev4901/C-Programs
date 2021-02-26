#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num,i,d,garb;
	int arr[] = {1,2,3,4,5,6,7};
	num=7;
	
    for(i=0; i<(num-1)/2; i++)
    {
        d=num - 1 - i;
        garb = arr[i];
        arr[i] = arr[d];
        arr[d] =  garb;
    }   


    for(i = 0; i < num; i++)
        printf("%d ",arr[i]);

}
 

