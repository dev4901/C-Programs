#include <stdio.h>
#include<stdlib.h>

int main(void) {
	// your code goes here
	int i=0,*number,j,flag;
	number = (int*)malloc(1*sizeof(int));
	while(1)
	{
	    scanf("%d",(number+i));
	    if(*(number+i)==42)
	        {
	        	flag=i;
	        }
	    else if(*(number+i)>=99)
	        {
	        	break;
	        }	    
        i++;
	    int *num = (int*)realloc(number,sizeof(int)*(i));
	    number=num;	    
	}
	for(j=0;j<flag;j++)
	{
	    printf("%d\n",*(number+j));
	}
	return 0;
}

