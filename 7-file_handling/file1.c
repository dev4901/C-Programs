#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fpoint,*fstore;
	fpoint = fopen("adult.txt","r");
	fstore = fopen("store2.txt","w+");

	char *s = malloc(170*sizeof(char));
	char *copy = malloc(170*sizeof(char));
	
	int column,row=1,flag=0;
	s=fgets(s,170,fpoint);
	char*value;
	while(s)
	{
		strcpy(copy,s);
		value = strtok(s,", ");
		column = 1;
		while(value)
		{
			if(value==NULL)
				break;
			if(column==1)                                                       
			{
				//printf("%d. attribute%d : %s, ", row, colum, value);
				int age = atoi(value);
				if(age>45)                                                       // age filter //
				{
					//fprintf(fstore, "%d. attribute%d: %d, ", row, colum, age);
				}
				else
				{
					break;	
				}
			}
			else if(column==2)                                                   
			{
				//printf("attribute%d : %s, ", colum, value);
				//fprintf(fstore, "attribute%d: %s, ", colum, value);
				int cmp = strcmp(value,"State-gov");                             // workplace filter //
				if(cmp==0)
				{
					
				}
				else
				{
					break;
				}
			}
			/*else if(column==3)
			{
				//printf("attribute%d : %s, ", colum, value);
				//fprintf(fstore, "attribute%d: %s, ", colum, value);
				int cmp = strcmp(value,"State-gov");                             // final-weight //
				if(cmp==0)
				{
					
				}
				else
				{
					break;
				}
			}*/
			else if(column==4)
			{
				//printf("attribute%d : %s, ", colum,  value);
				//fprintf(fstore, "attribute%d: %s, ", colum, value);
				int cmp = strcmp(value,"Bachelors");                             // Education filter //
				if(cmp==0)
				{
					//fprintf(fstore, "attribute%d: %s \n ", colum, value);
					flag=1;
				}
			}
			/*else if(column==15)
			{
				//printf("attribute%d: %s\n", colum, value);
				//fprintf(fstore, "attribute%d: %s", colum, value);
				int cmp = strcmp(value,">50K");
				int cmp2 = strcmp(value,"<=50K");
				if(cmp==0 || cmp2==0)
				{
					flag=1;
					fprintf(fstore, "attribute%d: %s\n", colum, value);
				}
				else
				{
					break;
				}
			}*/
			column++;
			value = strtok(NULL,", ");
		}
		
		if(flag==1)
		{
			fputs(copy,fstore);
		}
		//value=NULL;
		row++;
		s=fgets(s,170,fpoint);
		flag=0;
	}
}