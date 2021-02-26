#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// printing the 1, 3 and 4 columns from file example.txt

int main()
{
	FILE *fpoint,*fstore;
	char *s = malloc(50*sizeof(char));
	char *copy = malloc(50*sizeof(char));
	fpoint = fopen("example.txt","r");
	fstore = fopen("store.txt","w+");
	int colum,row=1;
	s=fgets(s,50,fpoint);
	char*value;
	while(s)
	{
		strcpy(copy,s);
		value = strtok(s,", ");
		colum = 1;
		while(value)
		{
			if(value==NULL)
				break;
			if(colum==1)
				{printf("attribute1 : %s, ", value);}
			else if(colum==3)
				{printf("attribute3 : %s, ", value);}
			else if(colum==4)
				{printf("attribute4 : %s \n\n", value);}
			colum++;
			value = strtok(NULL,", ");
		}
		fputs(copy,fstore);
		//value=NULL;
		row++;
		s=fgets(s,50,fpoint);
	}
}

