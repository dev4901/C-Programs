#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int at; //arrrival time
    int bt; //burst time
    int ct; //time at which the process is completed
    int tat; //turn-around-time - difference between ct and at (ct-at)
    int wt; //waiting-time - difference between at and tat (start_time-at)
    int start_time; // time at which process starts it's execution
}process;

void input(process *p, int number, FILE *fin, int* at_list); //takes input of at and bt values of total 
                                                        //processes and makes a list  of all sorted at's
void quicksort(int *a, int i, int j);
int partition(int *a, int low, int high);
void swap(int *a, int *b);
void process_seq(process *p, int *pr_list, int number, int *at_list); //makes the order of process to be executed
void print(process *p, int number, FILE *f);
void hline(FILE *f);

int main()
{
    int number, *at_list, *pr_list, i,time=0;
    process *p;
    FILE *fin = fopen("input2.txt","r+"), *fout = fopen("output.txt","a+");
    fscanf(fin,"%d",&number);
    p = malloc(number*sizeof(process));
    at_list = calloc(number,sizeof(int));
    pr_list = calloc(number,sizeof(int));
    input(p,number,fin,at_list);
    fprintf(fout,"\n");
    process_seq(p,pr_list,number,at_list);
    i=0;
    time = (p+*(pr_list+0))->at;
    for (i=0;i<number;i++)
    {
        if(time>=(p+*(pr_list+i))->at)
		{
			(p+*(pr_list+i))->start_time = time;
			(p+*(pr_list+i))->ct = (p+*(pr_list+i))->bt + (p+*(pr_list+i))->start_time;
        	time = (p+*(pr_list+i))->ct;
        	(p+*(pr_list+i))->tat = (p+*(pr_list+i))->ct - (p+*(pr_list+i))->at;
        	(p+*(pr_list+i))->wt = (p+*(pr_list+i))->start_time - (p+*(pr_list+i))->at;
		}
        else
		{
			(p+*(pr_list+i))->start_time = (p+*(pr_list+i))->at;
			(p+*(pr_list+i))->ct = (p+*(pr_list+i))->bt + (p+*(pr_list+i))->start_time;
        	time = (p+*(pr_list+i))->ct;
        	(p+*(pr_list+i))->tat = (p+*(pr_list+i))->ct - (p+*(pr_list+i))->at;
        	(p+*(pr_list+i))->wt = (p+*(pr_list+i))->start_time - (p+*(pr_list+i))->at;
		}
    }
    print(p,number,fout);
    fclose(fin); fclose(fout);
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

void print(process *p, int number, FILE *f)
{
    int i;
    fprintf(f,"Pid | at | bt  | start_time | ct | tat | wt   |\n");
    hline(f);
    for(i=0;i<number;i++)
    {
        fprintf(f,"%2d  | %-d  | %-2d  |%7d\t    | %-3d| %-4d| %-4d |\n", i, (p+i)->at, (p+i)->bt, (p+i)->start_time, (p+i)->ct, (p+i)->tat, (p+i)->wt);
    }
}

void hline(FILE *f)
{
    int i;
    for ( i = 0; i < 50; i++)
    {
        fprintf(f,"-");
    }
    fprintf(f,"\n");
}