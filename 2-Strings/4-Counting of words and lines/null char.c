/*Aim is to check whether space, null char and tab are identified different or same*/
#include<stdio.h>

int main()
{
	char arr[14];
	gets(arr);
	if(arr[5]=='\t')
		printf("its a tab\n");
	else if(arr[6]==' ')
		printf("its a space not null\n");
	else if(arr[2]=='\0')	
		printf("%c %c %c %c |",arr[4],arr[5],arr[6],arr[7]);
	printf("\nprogram \tterminated\r");
	printf("cursor returned");		
} 
