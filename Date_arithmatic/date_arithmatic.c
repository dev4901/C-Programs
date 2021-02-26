//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct date
{
	int day;
	int month;
	int year;
};

//functions declaration starts
/*---------------------------------------------------------------------------------------------------------------------------------------*/

int validate(struct date d1);               // returns 1 if date is valid and returns -1 if date is invalid

void nextdate(void);                       //prints the next consecutive date from the date entered by the user

void adddays(int monthl[], int size);      /* this function takes input of the date and no. of days from the user itself 
									      and prints the date after that that much days*/

void subtract(int arr[], int size);        /*does same as the adddays func but instead of adding it goes back to the date 
										   that comes when we go back the number of days from the date entered*/


int ahead(struct date d1,struct date d2);  // returns 1 when d1 is ahead of d2 // returns 0 when d2 is ahead of d1// returns -1 when d1 and d2 are same

int isleap(int year);                      // returns 1 if it is a leap year and returns 0 if it is not

void hline(void);      //prints a horizontal line consisting of 54 dashes

int repeat(void);      //will return 1 if the user wants to repeat the enclosed operation 
					   // return 0 if the user don't want to repat the enclode operation 

/*---------------------------------------------------------------------------------------------------------------------------------------*/
//Functions declaration ends here

/*---------------------------------------------------------------------------------------------------------------------------------------*/

//main function start

int main()
{
	int monthl[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, choose, flag,rep;
	struct date d1;
	do
	{
		printf("Following are some Date Arithmatic Operations that you can perform");
		hline();
		printf("1. validate a given date\n");
		printf("2. give the immediate next date\n");
		printf("3. Add days to a date to get a new date\n");
		printf("4. Subtract days from a date to get a new date\n");
		printf("5. Find which if the 2 dates are ahead of each other");
		hline();
		printf("Enter the index number of the operation that you want to execute - ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: //validate a given date
			hline();
			printf("1. validate a given date\n");
			printf("enter any date in th format (dd mm yyyy) - ");
			scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
			char buf1 = getchar();
			if (validate(d1))
			{
				printf("\n\nThe date is valid\n\n");
			}
			else
			{
				printf("\n\nthe date is invalid\n\n");
			}
			break;
		case 2: // give the immediate next date
			hline();
			printf("2. give the immediate next date\n");
			nextdate();
			break;
		case 3: // add days to a date to get next date
			hline();
			printf("3. Add days to a date to get a new date\n");
			adddays(monthl, 13);
			break;
		case 4: // subtract days from a date to get the date
			hline();
			printf("4. Subtract days from a date to get a new date\n");
			subtract(monthl, 13);
			break;
		case 5: // find which of the 2 dates are ahead of each other
			hline();
			printf("5. Find which if the 2 dates are ahead of each other \n ");
			{
				struct date d1, d2;
				printf("Enter the date d1 in format dd mm yyyy - ");
				scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
				printf("\n");
				printf("Enter the date d2 in format dd mm yyyy - ");
				scanf("%d %d %d", &d2.day, &d2.month, &d2.year);
				flag = ahead(d1, d2);
				if (flag == 1)
				{
					printf("\n\nd1 is ahead of d2\n\n");
				}
				else if (flag == 0)
				{
					printf("d2 is ahead of d1");
				}
				else
				{
					printf("d1 and d2 are the same date");
				}
			}		
			break;
		default: // default
			printf("Enter a valid index number");
			break;
		}
		rep = repeat();
	}
	while(rep);
	printf("\n");
	hline();
	printf("\nThank you for using this function!! \n");
	hline();
}

//main function ends

/*---------------------------------------------------------------------------------------------------------------------------------------*/

//Function definitions start
/*---------------------------------------------------------------------------------------------------------------------------------------*/

int isleap(int year) // returns 1 if it is a leap year and returns 0 if it is not
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

int validate(struct date d1) // returns 1 if date is valid and returns -1 if date is invalid
{
	if (d1.month > 12 || d1.day<=0)
	{
		return(0);
	}
	else if (d1.month == 2)
	{
		if (d1.day <= 28)
		{
			return(1);
		}
		else if (isleap(d1.year))
		{
			if (d1.day <= 29)
				return(1);
			else
				return(0);
		}
		else
		{
			return(0);
		}
	}
	else if (d1.day <= 30)
	{
		return(1);
	}
	else
	{
		if (d1.month < 8)
		{
			if (d1.month % 2 == 0)
			{
				return(0);
			}
			else
			{
				return(1);
			}
		}
		else
		{
			if (d1.month % 2 == 0)
			{
				return(1);
			}
			else
			{
				return(0);
			}
		}
	}
}

void adddays(int monthl[], int size)/* this function takes input of the date and no. of days from the user itself 
									  and prints the date after that that much days*/
{
	struct date d1, d2;
	int daysleft, adddays;
	printf("Enter the present date - ");
	scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
	printf("\n");
	printf("Enter the number of days you want to add - ");
	scanf("%d", &adddays);
	if (validate(d1)>0)
	{
		if (d1.month == 2)
		{
			if (isleap(d1.year))
			{
				daysleft = 29 - d1.day;
			}
			else
			{
				daysleft = 28 - d1.day;
			}
		}
		else
		{
			daysleft = monthl[d1.month] - d1.day;
		}
		d2 = d1;
		while (daysleft < adddays)
		{
			d2.month++;
			if (d2.month == 2)
			{
				if (isleap(d2.year))
				{
					daysleft += 29;
				}
				else
				{
					daysleft += 28;
				}
			}
			else if (d2.month == 13)
			{
				d2.month = 1;
				daysleft += monthl[d2.month];
				d2.year++;
			}
			else
			{
				daysleft += monthl[d2.month];
			}
		}

		if (d2.month == 2)
		{
			if (isleap(d2.year))
			{
				daysleft = daysleft - 29;
			}
			else
			{
				daysleft = daysleft - 28;
			}
		}
		else
		{
			daysleft = daysleft - monthl[d2.month];
		}
		d2.day = adddays - daysleft;
		printf("\n");
		printf("When we add %d days to the date %d/%d/%d we get the date %d/%d/%d \n\n", adddays, d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
	}
	else
	{
		printf("\nenter a valid date\n\n");
	}
}

void subtract(int monthl[], int size) 
{
	int subdays, daysleft;
	struct date d1, d2;
	printf("Enter the present date - ");
	scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
	printf("\n");
	printf("Enter the number of days you want to subtract - ");
	scanf("%d", &subdays);
	if (validate(d1)>0)
	{
		daysleft = d1.day;
		d2 = d1;
		while (daysleft<subdays)
		{
			d2.month--;
			if (d2.month==2)
			{
				if (isleap(d2.year))
				{
					daysleft+=29;
				}
				else
				{
					daysleft += 28;
				}
			}
			else if (d2.month==0)
			{
				d2.month = 12;
				daysleft += monthl[d2.month];
				d2.year--;
			}
			else
			{
				daysleft += monthl[d2.month];
			}
		}
		d2.day = daysleft - subdays;
		printf("\n");
		printf("when we go back %d days from the present date ", subdays);
		printf("%d/%d/%d ", d1.day, d1.month, d1.year);
		printf("we arrive at %d/%d/%d\n", d2.day, d2.month, d2.year);

	}
	else
	{
		printf("enter a valid date");
	}
}

void nextdate(void) //just prints the next consecutive date from the date entered by the user
{
	struct date d1,d2;
	printf("Enter any date in format(dd mm yyyy)- ");
	scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
	if (validate(d1)>0)
	{
		d2 = d1;
		if (d1.month == 2)
		{
			if (d1.day < 28)
			{
				d2.day++;
			}
			else if (d1.day == 29)
			{
				d2.day = 1;
				d2.month++;
			}
			else if (isleap(d2.year))
			{
				d2.day++;
			}
			else
			{
				d2.month = 3;
				d2.day = 1;
			}
		}
		else if (d1.day <= 29)
		{
			d2.day++;
		}
		else if (d1.day == 31)
		{
			if (d1.month != 12)
			{
				d2.day = 1;
				d2.month++;
			}
			else
			{
				d2.year++;
				d2.day = 1;
				d2.month = 1;
			}
		}
		else if (d1.month < 8)
		{
			if (d1.month % 2 == 0)
			{
				d2.month++;
				d2.day = 1;
			}
			else
			{
				d2.day++;
			}
		}
		else
		{
			if (d1.month % 2 == 0)
			{
				d2.day++;
			}
			else
			{
				d2.month++;
				d2.day = 1;
			}
		}
		printf("\nThe respective next date to that is : %d %d %d", d2.day, d2.month, d2.year);
	}
	else
	{
		printf("enter a valid date");
	}
	
}

int ahead(struct date d1,struct date d2) // returns 1 when d1 is ahead of d2 // returns 0 when d2 is ahead of d1// returns -1 when d1 and d2 are same                                     			                             
{
	if (validate(d1)>0 && validate(d2)>0)
	{
		if (d1.year != d2.year)
		{
			if (d1.year > d2.year)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (d1.month != d2.month)
		{
			if (d1.month > d2.month)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (d1.day != d2.day)
		{
			if (d1.day > d2.day)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
			return -1;
	}
	else
	{
		if (validate(d1)>0)
			printf("\nenter a valid d2 date\n");
		else if (validate(d2)>0)
			printf("\nenter a d1 date\n");
		else
			printf("\nenter valid dates\n");
	}
}

void hline(void) //prints a horizontal line consisting of 54 dashes
{
	int i;
	printf("\n");
	for (i = 0; i < 9; i++)
		printf("------");
	printf("\n");
}

int repeat(void) //return 0 if user deny// return 1 if it accepts
{
	char check[4];
	printf("\nDo you want to repeat the above operation ?:(Y/N) ");
	char buffer = getchar();
	//gets(check);
	fgets(check,3,stdin);
	//getch();
	printf("\nyour response is %s\n",check);
	printf("\n");
	//if (strcmp(check[0], "Y") == 0 || strcmp(check[0], "y") == 0)
	if(check[0]=='y' || check[0] == 'Y' || check[1] == 'y' || check[1] == 'Y' )
		return 1;
	else
		return 0;
}
/*---------------------------------------------------------------------------------------------------------------------------------------*/
//Function definitions end here
