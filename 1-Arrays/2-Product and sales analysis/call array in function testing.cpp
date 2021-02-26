#include<stdio.h>
void sumofrows(float a[][3], float b[], int i);

int main()
{
	float a[2][3];
	float b[3]={0};
	int i,j,k,l;
	k=2;
	i=j=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
			scanf("%f",&a[i][j]);
	}
	void sumofrows(float a[][3], float b[], int k);
	/*i=j=0;
	for(j=0;j<3;j++)
		printf("%d ",b[j]);*/
}

void sumofrows(float a[][3], float b[], int k)
{
	int i,sum,j;
	float h[k] = {0};
	i=j=sum=0;
	for(j=0;j<3;j++)
	{
		for(i=0;i<k;i++)
		{
			h[j]+=a[i][j];
			//b[j]=sum;
	    }
	}
	i=j=0;
	for(j=0;j<3;j++)
		b[j]=h[j];
		//printf("%f ",b[j]);
	for(i=0;i<3;i++)
		printf("%f ",b[i]);
	return;
}
