//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//const int j = 2;
//const int i = 3;

//float average(int s[][j],int i,int j);
//void tableinput(int s[][j],int i, int j);

int main()
{
	int str[3][2];
	extern int i=3,j=2;
	float avrage=0;
	
	float average(int s[][j],int i,int j);
	void tableinput(int s[][j],int i, int j);
	
	tableinput(str,i,j);
	
	avrage=average(str,i,j);
	
	printf("\n%f\n",avrage);	
} 

int i,j;
float average(int s[][j],int i, int j)
{
	int k,l, count;
	float sum=0,avg;
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			sum+=s[k][l];
		}
	}
	count=i*j;
	avg=sum/(float)count;
	return(avg);
}

void tableinput(int s[][j],int i, int j)
{
	int k,l;
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			scanf("%d",&s[k][l]);
		}
	}
}
