#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char phone[10][10],first[100][12],middle[100][12],last[100][12],buffer[12];
	int count, i,j,c1,c2,c3;
	count=i=j=0;
	printf("enter the name of the customer in format \nfirst middle last name and then phone no. respectively\n");
	printf("for each new customer input press enter once to reach new line\n");
	printf("to terminate the input, when in new line press enter.\n");
	for(i=0;i<100;i++)  //input and counting of the entries starts here
	{
		scanf("%s %s %s %s %s",first[i], middle[i], last[i], phone[i]);
		if(first[i][0]=='no') 
			break;	
	}		
	count=i; //input and counting of the entries ends here
	for(i=1;i<count;i++) //sorting starts here
	{
		for(j=0;j<(count-1);j++)
		{
			c1=strcmp(last[j],last[j+1]);
			c2=strcmp(first[j],first[j+1]);
			c3=strcmp(middle[j],middle[j+1]);
			if(c1>0)
			{
				strcpy(buffer,last[j]);
				strcpy(last[j],last[j+1]);
				strcpy(last[j+1],buffer);
				strcpy(buffer,first[j]);
				strcpy(first[j],first[j+1]);
				strcpy(first[j+1],buffer);
				strcpy(buffer,middle[j]);
				strcpy(middle[j],middle[j+1]);
				strcpy(middle[j+1],buffer);
				strcpy(buffer,phone[j]);
				strcpy(phone[j],phone[j+1]);
				strcpy(phone[j+1],buffer);
			}
			else if(c2>0)
			{
				strcpy(buffer,last[j]);
				strcpy(last[j],last[j+1]);
				strcpy(last[j+1],buffer);
				strcpy(buffer,first[j]);
				strcpy(first[j],first[j+1]);
				strcpy(first[j+1],buffer);
				strcpy(buffer,middle[j]);
				strcpy(middle[j],middle[j+1]);
				strcpy(middle[j+1],buffer);
				strcpy(buffer,phone[j]);
				strcpy(phone[j],phone[j+1]);
				strcpy(phone[j+1],buffer);
			}
			else if(c3>0)
			{
				strcpy(buffer,last[j]);
				strcpy(last[j],last[j+1]);
				strcpy(last[j+1],buffer);
				strcpy(buffer,first[j]);
				strcpy(first[j],first[j+1]);
				strcpy(first[j+1],buffer);
				strcpy(buffer,middle[j]);
				strcpy(middle[j],middle[j+1]);
				strcpy(middle[j+1],buffer);
				strcpy(buffer,phone[j]);
				strcpy(phone[j],phone[j+1]);
				strcpy(phone[j+1],buffer);
			}
		}
	}                                          //sorting ends here
	for(i=0;i<count;i++)
	{
		printf("%s, ",middle[i]);
		printf("%s. ",first[i][0]);
		printf("%s ",middle[i][0]);
		printf(" %s \n",phone[i]);
	}
} 
