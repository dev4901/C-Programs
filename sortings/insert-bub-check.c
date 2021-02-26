#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* insertion(int *a, int count);
int* bubble(int *a, int count);
void printarr(int *a,int count);

int main()
{
	FILE *fstore;
	fstore = fopen("insert-bub-check.txt","w");
	int *array, count, i ,j;
	count = 8;
	array = (int*)calloc(count,sizeof(int));
	srand(clock());
	for ( i = 0; i < count; ++i)
	{
		/* code */
		*(array+i) = rand();
	}
	//printf("The raw array - ");
	//printarr(array,count);

	int *insort = insertion(array,count);
	int *bubsort = bubble(array,count);

	fprintf(fstore,"Raw array\t");
	fprintf(fstore,"Insertion sort\t");
	//printarr(insort,count);
	fprintf(fstore,"Bubble sort\n");
	//printarr(bubsort,count);
	
	for(i=0;i<count;i++)
	{
		fprintf(fstore,"%10d\t %12d\t %10d\n",*(array+i),*(insort+i),*(bubsort+i));
	}

}

int* insertion(int *a, int count)
{
	int *insort,i,j;
	insort = (int*)malloc(count*sizeof(int));
	for(i=0;i<count;i++)
	{
		*(insort+i) = *(a+i);
	}
	for(i=1;i<count;i++)
	{
		int key = *(insort+i);
		j=i-1;
		while(*(insort+j) > key && j>=0)
		{
			*(insort+j+1) = *(insort+j); *(insort+j) = key;
			j--;
		}
	}
	return insort;
}

int* bubble(int *a, int count)
{
	int *bub,i,j;
	bub = (int*)malloc(count*sizeof(int));
	for(i=0;i<count;i++)
	{
		*(bub+i) = *(a+i);
	}

	for(i=1;i<count;i++)
	{
		for(j=0;j<(count-1);j++)
		{
			if(*(bub+j)>*(bub+j+1))
			{
				int key = *(bub+j);
				*(bub+j) = *(bub + j+1);
				*(bub+j+1) = key;
			}
		}
	}

	return bub;
}

void printarr(int *a, int count)
{
	int i;
	printf("\n");
	for (int i = 0; i < count; ++i)
	{
		/* code */
		printf("%d, ", *(a+i));
	}
	printf("\n\n");

}