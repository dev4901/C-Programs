#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int minimum(int *arr, int start, int end);

int main()
{
    FILE *fin;
    fin = fopen("selection1.txt","w+");
    int count=6, *array = malloc(count*sizeof(int));
    
	//scanning the unsorted array from the file
	/*for(int i=0;i<count;i++)
	{
        *(array+i) = rand();
		//fscanf(fin,"%d",(array+i));
    } */

	//printing the unsorted array to the file for scanning it afterwards
	//fprintf(fin,"The unsorted array is:\n");
	srand(clock());
	/*for (int i = 0; i < count; i++)
	{
		fprintf(fin,"%d\n",rand());
	}*/ 
	
	for(int i=0;i<count;i++)
	{
		*(array+i) = rand();
		fprintf(fin,"%d\n",*(array+i));
		//fscanf(fin,"%d",(array+i));
    }

	//selection sorting starts
	//fprintf(stdout,"\nminimums are:\n");
	for (int i = 0; i < (count-1); i++)
	{
		int buffer,min_i;
		min_i = minimum(array,i,count);
		//fprintf(stdout,"%d. minimum is : %d\n",i+1,*(array+min_i));
		buffer = *(array+i);
		*(array+i) = *(array+min_i);
		*(array+min_i) = buffer;
	}
	//selection sorting ends
	
	//printing the sorted array
	fprintf(fin,"\n\nThe sorted array is:\n");
	for (int i = 0; i < count; i++)
	{
		fprintf(fin,"%d\n",*(array+i));
	}
	
    return 0;
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
