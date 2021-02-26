//Aim - To check whether the if condition can be followed by scanf function in recording the input of 3 2D char arrays
#include<stdio.h>
#include<string.h>

/*operate - enter the values for just 2 entries. At the starting of 3rd entry,press space and then enter
  format for input - enter first_name<space>last_name<space>phone_no.
  required output - when pressed space and enter at the starting of the 3rd line, the input should terminate and should
  print 'passed' and then the values entered by you in the same format and if the 'if' function doesn't operate 
  then it should ask for input of other 2 parameters of the 3rd entry and then after inputting that entries, it'll
  print all the entered data*/

int main()
{
	char phone[5][6],first[5][6],last[5][6];	
	scanf("%s %s %s", first[1],last[1],phone[1]);
	scanf("%s %s %s",first[2],last[2],phone[2]);
	scanf("%s",first[3]);
	if(first[3][0]==' ')
	{
		printf("\n passed  \n");
	}
	else
	{
		scanf("%s %s",last[3],phone[3]);
	}
	printf("%s %s %s",first[1],last[1],phone[1]);
	printf("\n%s %s %s",first[2],last[2],phone[2]);
	printf("\n%s %s %s",first[3],last[3],phone[3]);

} 
//result - 
