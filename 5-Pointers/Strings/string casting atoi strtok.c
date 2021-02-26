#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int a,b,c;
	char *ptr,time[12]="03:23:43PM",*token,*hour,*minute,*second,*s;
 /*	ptr=time;
	a=atoi(ptr);
	token=strtok(ptr,"P");
	//token=strtok( 0 ,":");
	printf("a is %d",a);
	printf("\nthe token is %s",token);
	printf("\nthe s+8 is %c",*(ptr+7)); */
	/*a=49;
	ptr=(char*)&a;
	itoa(a,ptr,10);
	token=":23:23";
	strcat(ptr,token);
	printf("ptr is %s",ptr);	*/	
	s="13:35:45AM";
	hour=strtok(s, ":");
	printf("hour is %s\n",hour);
    hour=strtok(s,":");
    printf("hour is %s\n",hour);
    hour=strtok(s,":");
    printf("hour is %s\n",hour);
    //printf("hour is %s, minute is %s, seconds is %s",hour,minute,second);
}
 

