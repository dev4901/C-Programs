#include<stdio.h>

struct time
{
	int seconds;
	int minute;
	int hour;
};

void update(struct time t);

int main()
{
	struct time t;
	update(t);
} 

void update(struct time t)
{
	printf("enter the current time : ");
	scanf("%d %d %d",&t.hour,&t.minute,&t.seconds);
	t.seconds++;
	if(t.seconds==60)
	{
		t.seconds=00;
		t.minute++;
	}
	if(t.minute==60)
	{
		t.minute=00;
		t.hour++;
	}
	if(t.hour==24)
	{
		t.hour=t.seconds=t.minute=0;
	}
	printf("%2d : %2d : %2d",t.hour,t.minute,t.seconds);
}

