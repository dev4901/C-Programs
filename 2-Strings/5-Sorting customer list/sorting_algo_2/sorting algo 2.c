#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char first[10][20], middle[10][20], last[10][20], phone[10][15], name[10][70], buffer[70];
	int count, i, j, c1, c2, c3, c4;
	//taking and organising the input
	for (i = 0; i < 10; i++)
	{
		scanf("%s %s %s %s", first[i], middle[i], last[i], phone[i]);
		c1 = strcmp(first[i], "stop");
		c2 = strcmp(middle[i], "the");
		c3 = strcmp(last[i], "input");
		c4 = strcmp(phone[i], "process");
		if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0)
			break;
		strcpy(buffer, last[i]);
		strcat(buffer, ",");
		strncat(buffer, first[i],1);
		strcat(buffer, ".");
		strncat(buffer, middle[i],1);
		strcat(buffer, " ");
		strcat(buffer, phone[i]);
		strcpy(name[i], buffer);
	}
	
	count = i;

	//bubble sorting 
	for (i = 1; i < count; i++)
	{
		for ( j = 0; j < (count-1); j++)
		{
			c1 = strcmp(name[j], name[j + 1]);
			if (c1 > 0)
			{
				strcpy(buffer, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], buffer);
			}
			else
				continue;
		}
	}

	printf("\nThe results are...\n");

	//printing 
	for ( i = 0; i < count; i++)
	{
		printf("%s\n", name[i]);
	}
}
