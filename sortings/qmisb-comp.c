#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* insertion(int *a, int count);
int* bubble(int *a, int count);
int minimum(int *arr, int start, int end);
int* selection(int*array,int count);
int partition(int *a, int low, int high);
void quicksort(int *a, int i, int j);
void swap(int *a, int *b);
void merge(int *arr, int a1, int a2, int b1, int b2);
void mergesort(int *arr,int i,int j);

int main()
{
	int *array, count, i ,j=0,*data, data_count = 130;
    FILE *fstore;
	clock_t total1;
	total1 = clock();
    fstore = fopen("qmisb-comp.txt","w+");
	double *insort_time,*bubsort_time,*selectsort_time,*mergesort_time,*quicksort_time;
    data = calloc(data_count,sizeof(int));
	insort_time = calloc(data_count,sizeof(double));
	bubsort_time = calloc(data_count,sizeof(double));
    selectsort_time = calloc(data_count,sizeof(double));
    mergesort_time = calloc(data_count,sizeof(double));
    quicksort_time = calloc(data_count,sizeof(double));
	for(count=1000;count<=20000;count+=200)
	{
		array = malloc(count*sizeof(int));
        int *mersort = malloc(count*sizeof(int));
        int *qsort = malloc(count*sizeof(int));
        //int *insort = malloc(count*sizeof(int));
        //int *bubsort = malloc(count*sizeof(int));
        //int *selectsort = malloc(count*sizeof(int));
        *(data+j) = count;
        srand(clock());
		for ( i = 0; i < count; ++i)
		{
			*(array+i) = rand();
            *(mersort+i) = *(qsort+i) = *(array+i);
		}
		
        //performing the sorting algos and computing the time by each of them
        clock_t i1,i2,b1,b2,s1,s2,m1,m2,q1,q2;
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
        m1 = clock();
        mergesort(mersort,0,count-1);
        m2 = clock();
        *(mergesort_time+j) = (double)(m2-m1)/CLOCKS_PER_SEC;
        q1 = clock();
        quicksort(qsort,0,count-1);
        q2 = clock();
        *(quicksort_time+j) = (double)(q2-q1)/CLOCKS_PER_SEC;

		free(array);free(selectsort);free(insort);free(bubsort);
        free(mersort);free(qsort);
		j++;
	}
	//printf("Time taken by is - \n");// time bubble insort select
	for ( i = 0; i < j; ++i)
	{
		/* code */
		fprintf(fstore,"%-12d %-12lf %-12lf %-12lf %-12lf %-12lf\n",*(data+i), *(bubsort_time+i), *(selectsort_time+i), *(insort_time+i),*(mergesort_time+i),*(quicksort_time+i));
	}
	free(bubsort_time); free(insort_time); free(selectsort_time); free(data);
    free(mergesort_time); free(quicksort_time);
    free(array);
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

void swap(int *a, int *b)
{
    int buffer;
    buffer = *a;
    *a = *b;
    *b = buffer;
}

void quicksort(int *a, int i, int j)
{
    if(i<j)
    {
        int pivot;
        pivot = partition(a,i,j);
        quicksort(a,i,pivot-1);
        quicksort(a,pivot+1,j);
    }
}

int partition(int *a, int low, int high)
{
    int i=low, pivot = *(a+high), j=high-1;
    while (j>=i)
    {
        if(*(a+i)>pivot)
        {
            if(*(a+j)<pivot)
            {
                swap((a+i),(a+j));
                i++;j--;
            }
            else{j--;continue;}
        }
        else if(*(a+j)<pivot)
        {
            if(*(a+i)>pivot)
            {
                swap((a+i),(a+j));
                i++;j--;
            }
            else{i++;}continue;               
        }
        else {i++;j--;}        
    }
    swap((a+i),(a+high));
    return (i);
}

void merge(int *arr, int a1, int a2, int b1, int b2)
{
    int i=a1,j=b1,k=0, count = b2-a1+1;
    int *buffer = calloc(count,sizeof(int));
    while(i<=a2 && j<=b2)
    {
        if (*(arr+i)<*(arr+j))
        {
            *(buffer+k)=*(arr+i);
            k++;i++;
        }
        else if (*(arr+i)>*(arr+j))
        {
            *(buffer+k)=*(arr+j);
            k++;j++;
        }
        else if (*(arr+i)==*(arr+j))
        {
            *(buffer+k) = *(arr+i);
            k++;i++;j++;
        }
    }

    while (i<=a2)
    {
        *(buffer+k) = *(arr+i);
        k++; i++;
    }

    while (j<=b2)
    {
        *(buffer+k) = *(arr+j);
        k++;j++;
    }
    
    for(i=a1, k=0;i<=b2;i++, k++)
    {
        *(arr+i) = *(buffer+k);
    }
    
}

void mergesort(int *arr,int i,int j)
{
    if(i<j)
    {
        int divide = (i+j)/2;
        mergesort(arr,i,divide);
        mergesort(arr,divide+1,j);
        merge(arr,i,divide,divide+1,j);
    }
}
