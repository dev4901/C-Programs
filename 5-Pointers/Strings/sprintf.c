#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int hr,hournew;
    char *token,*minute,*second,*s,time[13];
    printf("enter time - ");
    fgets(time,11, stdin);
    s=time;
    token = (char*)malloc(20);
    minute = (char*)malloc(20);
    second = (char*)malloc(20);
    hr=atoi(s);
    if(*(s+8)=='P' && hr!=12)
    {
        hournew=hr+12;
    }
    else if (*(s+8)=='A' && hr==12) {
        hournew=00;
    }
    else {
        strncpy(token,s,8);
        printf("token is %s",token);
        exit(1);
    }
	token = strtok(s,":");
    token = strtok(NULL,":");
    strcpy(minute, token);
    token = strtok(NULL,":");
    strcpy(second,token);
    //itoa(hournew,token,10);
    if(*(s+8)=='A' && hr==12)
    	sprintf(token,"0%d",hournew);
    else
    	sprintf(token,"%d",hournew);
    strcat(token,":");
    strcat(token,minute);
    strcat(token,":");
    strncat(token,second,2);
    printf("token is %s",token);
}
