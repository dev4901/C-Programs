/*aim is to check whether new line and tab can be identified in if statemen or not*/
#include<stdio.h>

int main()
{
	char arr[35];
	int i,j;
	for(i=0;i<35;i++)
	{
		arr[i]=getchar();
		if(arr[i]=='\n')
			break;
	}
	printf("%d",i);
} 
