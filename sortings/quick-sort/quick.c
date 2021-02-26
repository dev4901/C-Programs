#include<stdio.h>
#include<stdlib.h>

int partition(int *a, int low, int high);
void quicksort(int *a, int i, int j);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    int count=9, *a = malloc(count*sizeof(int));
    FILE *fin, *fout;
    fin = fopen("quick.txt","r");
    fout = fopen("quick.txt","a");
    for (int i = 0; i < count; i++)
    {
        fscanf(fin,"%d ", (a+i));
    }
    
    quicksort(a,0,count-1);

    fprintf(fout,"the sorted array:\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(fout,"%d\n",*(a+i));
    }

    return 0;
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
    fprintf(stdout,"\nbetween %d and %d: \n",low, high);
    while (j>=i)
    {
        if(*(a+i)>pivot)
        {
            if(*(a+j)<pivot)
            {
                swap((a+i),(a+j));
                fprintf(stdout,"swaped %d and %d - ",i,j);
                i++;j--;
            }
            else{j--;continue;}
        }
        else if(*(a+j)<pivot)
        {
            if(*(a+i)>pivot)
            {
                swap((a+i),(a+j));
                fprintf(stdout,"swaped %d and %d - ",i,j);
                i++;j--;
            }
            else{i++;}continue;               
        }
        else {i++;j--;}        
    }
    swap((a+i),(a+high));
    for(int k=low;k<=high;k++){fprintf(stdout,"%d ", *(a+k));}
    fprintf(stdout,"\n");
    return (i);
}