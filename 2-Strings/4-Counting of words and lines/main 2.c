#include<stdio.h>
#include<string.h>

int main()
{
	char line[100];
	int i,j,k,characters,words,lines;
	i=j=k=0;
	characters=lines=words=0;
	//words=1;
	printf("enter the paragraph\n");
	printf("to end the input, press enter key at the starting of the new line\n");
	for(i=0; ;)//main loop for counting lines and characters
	{
		for(j=0;j<100;j++) // loop for counting no. of characters entered in the line
		{
			line[j]=getchar();
			if(line[j]=='\n')
				break;
		}
		line[j]='\0';
		if(line[0]=='\0') 
			break; 
		else
		{
			for(k=0;k<j;k++) // loop to calculate no. of words in a particular line
			{
				if(k=0)
				{
					if(line[k]!=' ' || line[k]!='\t')
					{
						words++;
					}
				}
				else if(line[k]==' ' || line[k]=='\t')
				{
					if(line[k+1]==' ')
					{
						continue;
					}
					words++;	
				}
			}
			
			characters+=strlen(line);
			lines+=1;	
		}	
	}
	//characters=characters - lines;
	printf("number of lines are - %d\n",lines);
	printf("number of characters are - %d\n",characters);
	printf("number of words are - %d\n",words);	
	
} 
