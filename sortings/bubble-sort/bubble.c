#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* bubble(int *a, int count);


int main()
{
	int *array, count, i ,j;
	clock_t t; double time_taken;
	t = clock();
	count = 6;
	array = (int*)calloc(count,sizeof(int));
	srand(clock());
	fprintf(stdout,"Unsorted array is:\n");
	for ( i = 0; i < count; ++i)
	{
		/* code */
		*(array+i) = rand();
		fprintf(stdout,"%d ",*(array+i));
	}
	fprintf(stdout,"\n");
//	printarr(array,count);

	int *bubsort = bubble(array,count);

	t = clock() - t;
	
	fprintf(stdout,"sorted array is:\n");
	for ( i = 0; i < count; ++i)
	{
		fprintf(stdout,"%d\n",*(bubsort+i));
	}
	fprintf(stdout,"\n");

	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("time taken - %lf \n", time_taken);
}

int* bubble(int *a, int count)
{
	int *bub,i,j,swap_count;
	bub = (int*)malloc(count*sizeof(int));
	for(i=0;i<count;i++)
	{
		*(bub+i) = *(a+i);
	}

	for(i=1;i<count;i++)
	{
		swap_count=0;
		for(j=0;j<(count-1);j++)
		{
			if(*(bub+j)>*(bub+j+1))
			{
				int key = *(bub+j);
				*(bub+j) = *(bub + j+1);
				*(bub+j+1) = key;
				swap_count++;
			}
		}
		if(swap_count==0)
		{
			break;
		}
	}

	return bub;
}
