/*Aim - To check whether the input of a string can be terminated using 
 getchar function ONLY for 'first' char array in a 'for loop' */

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
		for(j=0;j<6;j++)  // input of first array starts
		{
			first[i][j]=getchar();
			if(first[i][j]==' ' || first[i][j]=='\n')
				break;
		}                // input of first array ends
			
		if(first[i][0]=='\n')
			break;
		scanf("%s %s",last[i],phone[i]); //input of last and phone arrays.Each terminates with a space 
	}
	printf("%s%s %s",first[0],last[0],phone[0]);
	
} 

//Result - terminates after entering just 3 values , while required was 5 entries.
