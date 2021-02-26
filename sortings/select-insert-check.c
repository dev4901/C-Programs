#include<stdio.h>
#include<stdlib.h>

int minimum(int *arr, int start, int end);
int* insertion(int *arr, int count);

int main()
{
    FILE *fin;
    fin = fopen("selection1.txt","a+");
    int count=6, *array = malloc(count*sizeof(int));
    
	//scanning the unsorted array from the file
	for(int i=0;i<count;i++)
	{
        //*(array+i) = rand();
		fscanf(fin,"%d",(array+i));
    }

	//printing the unsorted array
	fprintf(fin,"The unsorted array is:\n");
	for (int i = 0; i < count; i++)
	{
		fprintf(fin,"%d\n",*(array+i));
	}
	

	//selection sorting starts
	for (int i = 0; i < (count-1); i++)
	{
		int buffer,min_i;
		min_i = minimum(array,i,count);
		buffer = *(array+i);
		*(array+i) = *(array+min_i);
		*(array+min_i) = buffer;
	}
	//selection sorting ends
	
	//printing the selection sorted array
	fprintf(fin,"\n\nThe sorted array is:\n");
	for (int i = 0; i < count; i++)
	{
		fprintf(fin,"%d\n",*(array+i));
	}
	
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

int minimum(int *arr, int start, int end)
{
    int i,min,index;
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

