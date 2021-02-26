//program is for evaluating a test 
#include<stdio.h>
#include<conio.h>

int main()
{
	char key[6],response[6];
	int incorrect[6]={0};
	int i,j,n,k,mark,count,student;
	i=j=k=mark=count=student=0;
	printf("enter the answer key - \n");
	for(i=0;i<5;i++)  //reading answer key into the array 'key[]'
	{
		scanf("%c",&key[i]);
	}
	scanf("%c",&key[i]);
	key[i]='/0' ;
	printf("enter the no. of students whose \nresponses are to be checked - ");
	scanf("%d",&n);
	for(student=0;student<n;student++) //reading responses in 'responses[]' array and evaluating marks
	{
		printf("\nstudent - %d\n",student+1);
		printf("enter responses - \n");
		for(j=0;j<5;j++) //entering responses in array 'responses[]'
		{
			scanf("%c",&response[j]);
		 //comparing 'responses[]' array with 'key[]' array to find final marks  
		    if(response[j]==key[j])
		    {
			    mark+=1;
			    continue;
		    }
			else
		    {
				incorrect[j]=j+1;
				continue;
		    }
	    }
		printf("marks - %d out of 5 \n",mark);
		printf("incorrect ques are - \n");
		k=0;
		for(k=0;k<5;k++) //printing incorrect ques no.
		{
			if(incorrect[k]==0)
			{
				count+=1;
			}
			else
			{
				printf("%d",incorrect[k]);
			}
		}
		if(count==5)
		{
		printf("null");
	    }
    }
	getch();
}
