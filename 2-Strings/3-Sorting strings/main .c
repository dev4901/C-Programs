#include<stdio.h>
#include<string.h>

int main()
{
	void exchange(char list[][22],char sub[], int size, int a, int b );
	char list[5][22], sub[22];
	int i,j,k,check;
	//i=0;
	/*input of strings*/
	for(i=0;i<5;i++)
	{
		gets(list[i]);
	}
	/*bubble sorting starts*/
	for(k=0;k<4;k++)
	{
		for(j=0;j<4;j++)
		{
			check=strcmp(list[j],list[j+1]);
			if(check==1)
			{
				exchange(list,sub,5,j,j+1);
			}
		}
	}
	/*printing of ordered list*/
	for(i=0;i<5;i++)
	{
		puts(list[i]);
	}	
} 

void exchange(char list[][22], char sub[], int size, int a, int b)
{
	strcpy(sub,list[a]);
	strcpy(list[a],list[b]);
	strcpy(list[b],sub);
	
}
