#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int a1, int a2, int b1, int b2);
void mergesort(int *arr,int i,int j);

int main()
{
    FILE *fin,*fout;
    int count = 8, *arr;
    arr = calloc(count,sizeof(int));
    fin = fopen("merge.txt","r");
    fout = fopen("merge.txt","a");
    for (int i = 0; i < count; i++)
    {
        fscanf(fin,"%d ", (arr+i));
    }

    mergesort(arr,0,count-1);

    fprintf(fout,"\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(fout,"%d, ", *(arr+i));
    }
    printf("\n");
    return 0;
}

//array a a1->a2 and array b b1->b2
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
