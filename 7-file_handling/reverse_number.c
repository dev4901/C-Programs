#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void) {
	int num,*numbers,i=0,mod,count,power;

	scanf("%d",&num);
	
	numbers = (int*)malloc(num*sizeof(int));
	int *mod1; mod1 = (int*)calloc(num,sizeof(int));
	
	for(i=0;i<num;i++)
	{
	    scanf("%d",(numbers+i));
	    //printf("the %dth number is %d\n",i+1,*(numbers+i));
	    //printf("number %d is %d\n",i+1,*(numbers+i));
	}
	
	for(i=0;i<num;i++)
	{
	    mod = *(numbers+i);
	    count=0;
	    while(mod!=0)
	    {
	        //power = powe(10,count);
	        int pvalue = *(mod1+i)*10;
	        *(mod1+i) = pvalue + mod%10;
	        //printf("mode value is %d mod1 is %d , pvalue is %d\n",mod%10,*(mod1+i), pvalue);
	        mod=mod/10;
	        count++;
	    }
	}

	//printf("\nthe reversed numbers are:\n");
	for (i = 0;i < num;i++)
	{
		/* code */
		printf("%d\n",*(mod1+i));
	}
	
	free(numbers); free(mod1);

	return 0;
}
