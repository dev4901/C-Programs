#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int at; //arrrival time
    int bt; //burst time
}process;


/*takes input of at and bt values of total processes and makes a list  of all sorted at's */
void input(process *p, int number, FILE *fin, int* at_list);
void quicksort(int *a, int i, int j);
int partition(int *a, int low, int high);
void swap(int *a, int *b);
/*gets the sequence of indexes in *pr_list in which the processes are to be executed*/
void process_seq(process *p, int *pr_list, int number, int *at_list);

int main(int argc, char const *argv[])
{
    int number, *at_list, *pr_list, i;
    process *p;
    FILE *fin = fopen("check.txt","r+"), *fout = fopen("check.txt","a+");
    fscanf(fin,"%d",&number);
    p = malloc(number*sizeof(process));
    at_list = calloc(number,sizeof(int));
    pr_list = calloc(number,sizeof(int));
    input(p,number,fin,at_list);
    fprintf(fout,"\n");
    process_seq(p,pr_list,number,at_list);
    fprintf(fout,"processes in order: \n");
    for ( i = 0; i < number; i++)
    {
        fprintf(fout,"Pid - %d \n", *(pr_list+i));
    }
}

void input(process *p,int number, FILE *fin, int* at_list)
{
    int i,j;
    for(i=0;i<number;i++)
    {
        fscanf(fin,"%d %d", &(p+i)->at, &(p+i)->bt);
    }
    for ( j=0; j<number; j++)
    {
        *(at_list+j) = (p+j)->at; 
    }
    quicksort(at_list,0,number-1);
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

void process_seq(process *p, int *pr_list, int number, int *at_list)
{
    int i,j,exclude[number], flag=0;//if flag zero, index is valid, flag=1 index invalid
    *(pr_list+0)=-1;
    exclude[0]=-1;
    for(i=0;i<number;i++)
    {
        flag=0;
        for(j=0;j<number;j++)
        {
            flag=0;
            for(int k=0;k<i;k++)
            {
                if(exclude[k]==j)
                {
                    flag=1;
                }
            }
            if(flag==0)
			{
                if(*(at_list+i)==(p+j)->at)
                {
                    *(pr_list+i)=j;
                    exclude[i]=j;
                	break;
            	}
            }
			else
			{
				continue;
			}
			
        }
    }
}