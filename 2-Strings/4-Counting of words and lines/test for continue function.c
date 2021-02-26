#include<stdio.h>

int main()
{
	int j,i;
	for(i=0;i<4;i++)
	{
		printf("i = %d \n",i,j);
		for(j=0;j<4;j++)
		{
			
			if(i==2)
			{
				if(j==2)
				{
					// printf("Reched j=2\n");
					continue;
				}
			}
			printf("\tj = %d\n",j);
			
			if(j==3 && i==2)
			{
				printf("the continue function just jumped inner loop\n");
			}
			
			else if(j==3 && i==3)
			{
				printf("the continue function jumped both loops\n");
			}
		}
	}
}

