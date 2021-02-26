/*entering the values in a 1d array in tabular form*/
/*input - 1 2 3 
          0 3 2
   output is in the same format!*/
#include<stdio.h>

int main()
{
	int i,j,a[6];
	i=j=0;
	for(j=0;j<2;j++)
	{
	    for(i=0;i<3;i++)
	    {
		    if(j==0)
		       scanf("%d",&a[i]);
		    else
		    {
			   scanf("%d",&a[i+3]);
		    }
        }
    printf("\n");
	}
	i=0;
	j=0;
	for(j=0;j<2;j++)
	{
	   for(i=0;i<3;i++)
	    {
		   if(j==0)
		   {
	 	      printf("%d ",a[i]);
	       }
		   else if(j==1)
		   {
			  printf("%d ",a[i+3]);
		   }
	    }
	    printf("\n");
    } 
  
}
