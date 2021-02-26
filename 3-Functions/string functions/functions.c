# define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

int palindrome(char str[]);
int occurance(char str[], char letter);
void comparison(char str1[], char str2[]);

int main()
{
	char str1[20], letter, str2[20], buffer;
	int choose, compare, check;
	printf("enter a string - ");
	gets(str1);
	printf("enter the one of the operations that you want ot execute - \n");
	printf("1. check palindrome\n2. find a given character\n3. compare 2 strings\n");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		check = palindrome(str1);
		if (check == 1)
			printf("the string is a palindrome");
		else
			printf("the string is not a palindrome");
		break;
	case 2:
		printf("enter the characer whose occurance you want to find - ");
		buffer = getchar();
		letter = getchar();
		printf("\n");
		check = occurance(str1, letter);
		if (check < 0)
			printf("the letter %c is not present in the string", letter);
		else
			printf("the letter is present at index %d of the string.", check);
		break;
	case 3:
		printf("enter the second string with which you want to compare to - ");
		buffer = getchar();
		gets(str2);
		comparison(str1, str2);
		break;
	}
}

int palindrome(char str[])
{
	int length = strlen(str);
	int i, check;
	if (length % 2 == 0)
		check = length / 2;
	else
		check = (length - 1) / 2;

	for (i = 0; i < check; i++)
	{
		if (str[i] == str[length - 1 - i])
			continue;
		else
			break;
	}
	if ((i-1) == (check - 1) && str[check-1] == str[length - 2 - check])
		return 1;
	else if ((i-1) == (check - 1) && str[check-1] != str[length - 2 - check])
		return 0;
	else if (i != check)
		return 0;
}

int occurance(char str[], char letter)
{
	int length, i;
	length = strlen(str);
	for (i = 0; i < length; i++)
	{
		if (str[i] == letter)
			break;
		else
			continue;
	}
	if (str[i] == letter)
		return i;
	else
		return -1;
}

void comparison(char str1[], char str2[])
{
	int compare;
	compare = strcmp(str1, str2);
	if (compare < 0)
		printf("%s is alphabetically above %s \n \n", str1, str2);
	else if (compare > 0)
		printf("%s is alphabetically below %s \n\n", str2, str1);
	else
		printf("string 1 %s and string 2 %s are equal\n\n", str1, str2);
}