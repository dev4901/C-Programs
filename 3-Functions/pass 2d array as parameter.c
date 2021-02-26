//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int n;
void print(int arr[][n],int m,int n);

int main()
{
	int array[5][2]={1,2,3,23,45,32,76,32,52,54},m;
	m=3,n=1;
	print(array,m,n);
}

void print(int arr[][n],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
}
