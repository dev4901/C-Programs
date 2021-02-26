/*Aim - to check whether the input gets terminated after entering 'no' at the end of the line*/
//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

/*operate - max of 5 entries are allowed and max of 6 char per argument
  format for input - enter first_name<space>last_name<space>phone_no.
  required output - when entered 'no' at the starting of any new line, the input should terminate and should
  print the values entered by you in the same format*/

int main()
{
	char first[5][6],last[5][6],phone[5][6];
	int i,j,c;
	for(i=0;i<5;i++)
	{
		scanf("%s ",first[i]);
		c=strcmp(first[i],"no");
	/*	for (j=0;j<6;j++)
		{
			first[i][j] = getchar();
			if (first[i][j] == ' ' || first[i][j] == '\n')
			{
				first[i][j] = ' ';
				break;
			}
		}
		c=strcmp(first[i],"no "); */
		if(c==0)
		{
			break;
		}
		scanf("%s %s",last[i],phone[i]);
		if(first[i]=='y' && last[i]=='e' && phone[i]=='s')
		{
			break;
		}
	}
	for(j=0;j<=(i-1);j++)
	{
		printf("%s %s %s\n",first[j],last[j],phone[j]);
	}
} 

/*result - the input doesn't terminate after writing just 'no' , we need to right anything for the other 2 arrays to.*/
