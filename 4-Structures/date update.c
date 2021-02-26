
#include<stdio.h>
#include<string.h>

struct date
{
	int day;
	int month;
	int year;  
};

int validate(struct date d);
struct date increment(struct date d);
void hline(void);

int main()
{
	struct date d1,d2;
	int check,i;
	i=0;
	char ans[4];
	while(i==0)
	{
		printf("\n");
		hline();
		printf("enter any valid date in the format dd mm yyyy :\n");
		scanf("%d %d %d",&d1.day,&d1.month,&d1.year);
		check=validate(d1);
		if(check!=1)
		{
			printf("\nPlease enter a valid date\n");
		}
		else
		{
			d2=increment(d1);
			printf("\nThe respective next date to that is : %d %d %d",d2.day,d2.month,d2.year);
		}
		printf("\n\n");
		printf("Do you want to add another date ?:(Yes/No)\n");
		scanf("%s",ans);
		if(strcmp(ans,"Yes")==0 || ans[0]=='y')
		{
			i=0;
		}
		else
		{
			i=1;
		}
	}
	hline();
	printf("\n\nTHE END\n\n");
} 

int validate(struct date d1)
{
	if(d1.month>12)
	{
		return(-1);
	}
	else if(d1.month==2)
	{
		if(d1.day<=28)
		{
			return(1);	
		}
		else if(d1.year%4==0)
		{
			return(1);
		}
		else
		{
			return(-1);
		}
	}
	else if(d1.day<=30)
	{
		return(1);
	}
	else
	{
		if(d1.month<8)
		{
			if(d1.month%2==0)
			{
				return(-1);
			}
			else
			{
				return(1);
			}
		}
		else
		{
			if(d1.month%2==0)
			{
				return(1);
			}
			else
			{
				return(-1);
			}
		}
	}
}

struct date increment(struct date d1)
{
	struct date d2;
	d2=d1;
	if(d1.month==2)
	{
		if(d1.day<28)
		{
			d2.day++;	
		}
		else if(d1.day==29)
		{
			d2.day=1;
			d2.month++;
		}
		else if(d1.year%4==0)
		{
			d2.day++;
		}
		else
		{
			d2.month=3;
			d2.day=1;
		}
	}
	else if(d1.day<=29)
	{
		d2.day++;
	}
	else if(d1.day==31)
	{
		if(d1.month!=12)
		{
			d2.day=1;
			d2.month++;
		}
		else
		{
			d2.year++;
			d2.day=1;
			d2.month=1;
		}
	}
	else if(d1.month<8)
	{
		if(d1.month%2==0)
		{
			d2.month++;
			d2.day=1;
		}
		else
		{
			d2.day++;
		}
	}
	else
	{
		if(d1.month%2==0)
		{
			d2.day++;
		}
		else
		{
			d2.month++;
			d2.day=1;
		}
	}
	return(d2);	
}

void hline(void)
{
	int i;
	i=0;
	while(i<25)
	{
		printf("--");
		i++;
	}
	printf("\n");
}


