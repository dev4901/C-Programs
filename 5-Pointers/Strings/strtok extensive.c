#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *s,*hour,time[12],*minute,*second,*token,*hournew;
	scanf("%s",time);
	s=time;
	//s="13:35:45AM";
	token = (char*)malloc(9*sizeof(char));
	hournew = (char*)malloc(4*sizeof(char));
	minute = (char*)malloc(4*sizeof(char));
    second = (char*)malloc(4*sizeof(char));
	hour=strtok(s, ":");
	strcpy(hournew,hour);
	
	hour=strtok(NULL,":");
    strcpy(minute,hour);
    
	hour=strtok(NULL,":");
    strncpy(second,hour,2);
	strcat(token,hournew);
    strcat(token,":");
    strcat(token,minute);
    strcat(token,":");
    strncat(token,second,2);
    printf("\n\n the full token is %s",token);
}
