#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *arr, int a1, int a2, int b1, int b2);
void mergesort(int *arr,int i,int j);
int* insertion(int *arr, int count);

int main(int argc, char const *argv[])
{
    int count = 5; 
    FILE *fout = fopen("merge-insert-check.txt","w+");
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

    mergesort(arr,0,count-1);

    fprintf(fout,"\nThe merge sort -\n ");
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


