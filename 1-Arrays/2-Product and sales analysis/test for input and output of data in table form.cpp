#include<stdio.h>
/*test for input and output of data in tabular form*/

int main()
{
	int mfg[4][5],i,j;
	i=0;
	j=0;
	printf("enter the no. of mfg products - \n");
	//loop for input of no. mfg products 
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&mfg[i][j]);	
		}
	}
	//printing in table form with j column and i row 
	i=0;
	printf("\nno. of products mfg are - \n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(j==0)
				printf("| %d |",mfg[i][j]);
			else
				printf(" %d |",mfg[i][j]);	
		}
		printf("\n");
	}
}
