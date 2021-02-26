/*Aim - use the 'if' condition with getchar inside a 'for loop' for 'first' and 'last' char arrays to terminate the input of strings
		by pressing enter at the start of a next line */
#include<stdio.h>
#include<string.h>

/*operate - max of 5 entries are allowed and max of 6 char per array
  format for input - enter first_name<space>last_name<space>phone_no.
  required output - when pressed enter at the starting of any new line, the input should terminate and should
  print the values entered by you in the same format*/
  

int main()
{
	char first[5][6],last[5][6],phone[5][6];
	int i,j,count;
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)                           //input in first char array starts
		{
			first[i][j]=getchar();
			if(first[i][j]==' ' || first[i][j]=='\n')
				break;
		}                                          //input in first char array ends
			
		if(first[i][0]=='\n')
			break;
		scanf("%s",last[i]);                      //input for last char array
		
		for(j=0;j<6;j++)                         //input in phone char array starts
		{
			phone[i][j]=getchar();
			if(phone[i][j]=='\n')
				break;
		}                                        //input in phone char array ends
		phone[i][j]=' ';
	}
	
	count=i;
	
	for(i=0;i<=count;i++)
		printf("\n%s%s %s ",first[i],last[i],phone[i]);	
} 

/*result - terminates after writing just 3 lines,while required was 5 entries*/
