#include<stdio.h>
#include<string.h>
int m;
float average(float arr[],int m);

int main()
{
	float array[5]={5,2,4,8,9};
	int t;
	float avg;
	avg=average(array,5);
	printf("average of the array is %.2f",avg);
} 

float average(float arr[],int m)
{
	float sum,avg;
	int i;
	sum=avg=0;
	for(i=0;i<m;i++)
	{
		sum+=arr[i];
	}
	avg=sum/m;
	return(avg);
}
