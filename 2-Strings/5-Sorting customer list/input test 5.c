#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char first[5][6], middle[5][6], last[5][6], phone[5][6];
	int i,count,c1,c2,c3,c4;
	for(i=0;i<5;i++)
	{
		scanf("%s %s %s %s",first[i],middle[i],last[i],phone[i]);
		c1=strcmp(first[i],"stop");
		c2=strcmp(middle[i],"the");
		c3=strcmp(last[i],"input");
		c4=strcmp(phone[i],"process");
		if(c1==0 && c2==0 && c3==0 && c4==0)
			break;
	}
	
	count=i;
	printf("\n");
	
	for(i=0;i<(count);i++)
	{
		printf("%s,%c.%c %s\n",last[i],first[i][0],middle[i][0],phone[i]);
	}
}
