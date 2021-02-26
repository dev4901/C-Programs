#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* insertion(int *a, int count);
int* bubble(int *a, int count);
int minimum(int *arr, int start, int end);
int* selection(int*array,int count);

int main()
{
	int *array, count, i ,j=0,*data;
    FILE *fstore;
	clock_t total1;
	total1 = clock();
    fstore = fopen("isb-comp.txt","w+");
	double *insort_time,*bubsort_time,*selectsort_time;
    data = calloc(82,sizeof(int));
	insort_time = calloc(82,sizeof(double));
	bubsort_time = calloc(82,sizeof(double));
    selectsort_time = calloc(82,sizeof(double));
	for(count=1000;count<=5000;count+=50)
	{
		array = (int*)calloc(count,sizeof(int));
        *(data+j) = count;
        srand(clock());
		for ( i = 0; i < count; ++i)
		{
			*(array+i) = rand();
		}
		clock_t i1,i2,b1,b2,s1,s2;
		i1=clock();
		int *insort = insertion(array,count);
		i2=clock();
		*(insort_time+j) = (double)(i2-i1)/CLOCKS_PER_SEC;
		b1=clock();
		int *bubsort = bubble(array,count);
		b2=clock();
		*(bubsort_time+j) = (double)(b2-b1)/CLOCKS_PER_SEC;
        s1=clock();
        int* selectsort = selection(array,count);
        s2=clock();
        *(selectsort_time+j) = (double)(s2-s1)/CLOCKS_PER_SEC;
		free(array);free(insort);free(bubsort);free(selectsort);
		j++;
	}
	//printf("Time taken by is - \n");// time bubble insort select
	for ( i = 0; i < j; ++i)
	{
		/* code */
		fprintf(fstore,"%-12d %-12lf %-12lf %-12lf\n",*(data+i), *(bubsort_time+i), *(selectsort_time+i), *(insort_time+i));
	}
	free(bubsort_time); free(insort_time); free(selectsort_time); free(data);
	total1 = clock() - total1;
	double total = (double)total1/CLOCKS_PER_SEC;
	fprintf(stdout,"\ntotal time taken is %lf secs\n",total);
}

int* insertion(int *a, int count)
{
	int *insort,i,j;
	insort = malloc(count*sizeof(int));
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
	int *bub,i,j,swap_count;
	bub = malloc(count*sizeof(int));
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
				swap_count=1;
			}
		}
		if (swap_count==0)
		{
			break;
		}
	}

	return bub;
}

int* selection(int *a, int count)
{
    int *array = malloc(count*sizeof(int));
    for(int i=0;i<count;i++)
    {
        *(array+i) = *(a+i);
    }
    for (int i = 0; i < (count-1); i++)
	{
		int buffer,min_i;
		min_i = minimum(array,i,count);
		//fprintf(stdout,"%d. minimum is : %d\n",i+1,*(array+min_i));
		buffer = *(array+i);
		*(array+i) = *(array+min_i);
		*(array+min_i) = buffer;
	}
    return array;
}

int minimum(int *arr, int start, int end)
{
    int i,min,index=start;
    min = *(arr+start);
    for(i=start;i<end;i++)
    {
        if(min>*(arr+i))
        {    
            min = *(arr+i);
            index = i;
        }    
    }
    return index;
}
