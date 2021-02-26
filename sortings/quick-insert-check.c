#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *a, int low, int high);
void quicksort(int *a, int i, int j);
void swap(int *a, int *b);
int* insertion(int *a, int count);

int main()
{
    int count = 10; 
    FILE *fout = fopen("quick-insert-check.txt","w+");
    srand(clock());
    int*arr=calloc(count,sizeof(int));
    int *insort = malloc(count*sizeof(int));
    fprintf(fout,"The unsorted array -\n");
    for (int i = 0; i < count; i++)
    {
        *(arr+i) = rand();
        fprintf(fout,"%d ", *(arr+i));
    }
    fprintf(fout,"\n");
    
    insort = insertion(arr,count);

    quicksort(arr,0,count-1);

    fprintf(fout,"\nThe quick sort -\n ");
    for(int i=0;i<count;i++)
    {
        fprintf(fout,"%d\n",*(arr+i));
    }
    fprintf(fout,"\n");

    fprintf(fout,"The insertion sort -\n ");
    for(int i=0;i<count;i++)
    {
        fprintf(fout,"%d\n",*(insort+i));
    }
    fprintf(fout,"\n");

    return 0;
    return 0;
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
