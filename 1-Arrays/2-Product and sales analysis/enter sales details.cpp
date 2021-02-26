#include<stdio.h>
void arrayprint1d(float array[], int k);
//void arrayprint2d(float array[][6], int k);
//void weeks(float a[][6], float b[]);
//void products(float a[][6], float b[]);

int main()
{
	float m[5][6],s[5][6],c[6],mvalue[5][6],svalue[5][6], mweek[5],sweek[5],mprod[6],sprod[6],mtotal,stotal;
	int i,j,k, number;
	i=j=1;
	/*input of data in arrays m,s,c*/
	//input in array m
	printf("enter no. of products mfg - \n");
	for(i=1;i<5;i++)
	{
		for(j=1;j<6;j++)
		{
			scanf("%f",&m[i][j]);
		}
	}
	//input in array s
	i=j=1;
	printf("\nenter no. of products sold - \n");
	for(i=1;i<5;i++)
	{
		for(j=1;j<6;j++)
		{
			scanf("%f",&s[i][j]);
		}
	}
	//input in array c
	j=1;
	printf("\n enter cost of each type of product - \n");
	for(j=1;j<6;j++)
	{
		scanf("%f",&c[j]);
	}
	/*input finished*/
	/*calculations start*/
	
	//calculate mvalue and svalue
	i=j=1;
	for(i=1;i<5;i++)
	{
		for(j=1;j<6;j++)
		{
			mvalue[i][j]=m[i][j]*c[j];
			svalue[i][j]=s[i][j]*c[j];
		}
	}
	
	//calculate Mweek and Sweek
	i=j=1;
	//void weeks(mvalue[5][6],mweek[5]);
	for(i=1;i<5;i++)
	{
		mweek[i]=0;
		sweek[i]=0;
		for(j=1;j<6;j++)
		{
			mweek[i]+=mvalue[i][j];
			sweek[i]+=svalue[i][j];
		}
	}
	
	//calculate mproduct and sproduct
	i=j=1;
	//void products(mvalue[5][6],mprod[6]);
	for(j=1;j<6;j++)
	{
		mprod[j]=0;
		sprod[j]=0;
		for(i=1;i<5;i++)
		{
			mprod[j]+=mvalue[i][j];
			sprod[j]+=svalue[i][j];
		}
	}
	//calculate mtotal and stotal
	i=0;
	stotal=mtotal=0;
	for(i=1;i<5;i++)
	{
		stotal+=sweek[i];
		mtotal+=mweek[i];
	}
	
	/*calculation part ends*/
	
	/*main printing of information starts*/
	
	printf("\n\n");
	printf("\nfollowing is the list of things you can ask for - ");
	printf("\n 1) value of weekly production and sales");
	printf("\n 2) total value of all products manufactured");
	printf("\n 3) total value of all products sold");
	printf("\n 4) total value of each product manufactured and sold");
	printf("\n 5) end the program");
	
	
	while(1)
	{
		printf("\nSelect any option from the above and enter 5 to end the program\n");
		scanf("%d",&number);
		if(number==5)
		{
			printf("bye");
			break;
		}
		
		switch(number)
		{
			case 1: 
				   printf("values of products manufactured - \n");
				   k=5;
				   //void arrayprint2d(float svalue[][6], int k);
				   i=j=1;
				   for(i=1;i<5;i++)
				   {
				   		printf("week %d - ",i);
						for(j=1;j<6;j++)
				   		{
							if(j==1)
				   				printf("| %2.2f |",mvalue[i][j]);
				   			else
								printf(" %2.2f |",mvalue[i][j]);
						}
						printf("\n");
				   }
				   printf("\nvalues of products sold - \n");
				   i=j=1;
				   for(i=1;i<5;i++)
				   {
				   		printf("week %d - ",i);
						for(j=1;j<6;j++)
				   		{				   			
							if(j==1)
				   				printf("| %2.2f |",svalue[i][j]);
				   			else
								printf(" %2.2f |",svalue[i][j]);
						}
				   }
						printf("\n");
				   //void arrayprint2d(float mvalue[][6], int k);
				   printf("\n");
				   break;
			case 2:
				   printf("total value of all products manufactured is %f",mtotal);
				   break;
			case 3:
				   printf("total value of all products sold is %f",stotal);
				   break;
			case 4:
				   printf("\ntotal value of each product sold - \n");
				   k=6;
				   arrayprint1d(sprod,k);
				   //for(i=1;i<6;i++)
				   	//	printf("%.2f ",sprod[i]);
				   
				   //printf("\n total value of each product manufactured - \n");
				   //arrayprint1d(float mprod[], int k);
				   printf("\n");
				   break;
			default: break;  
		}
	}
	/*main printing of information ends*/

}

/*
void arrayprint2d(float array[][6], int l)
{
	int i,j;
	i=j=1;
	for(i=1;i<l;i++)
	{
		for(j=1;j<6;j++)
		{
			printf("%f",array[i][j]);
		}
		printf("\n");
	}
	return;
}*/

void arrayprint1d(float array[], int k)
{
	
	int i;
	//i=1;
	for(i=1;i<k;i++)
		printf("%.2f ",array[i]);
	return;
}
/*void weeks(float a[][6], float b[])
{
	int i,j;
	i=j=1;
	for(i=1;i<;i++)
	{
		for(j=1;j<q;j++)
			b[i]+=a[i][j];
	}
	
}
void products(float a[][6], float b[])
{
	int i,j;
	i=j=1;
	for(j=1;j<p;j++)
	{
		for(i=1;i<q;i++)
			b[j]+=a[i][j];
	}
}*/
