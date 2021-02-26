#include<stdio.h>

typedef struct 
{
	char name[25];
	int day;
	int month;
	int year;
	float salary;
}personal;

int main()
{
	personal person1;
	printf("enter the name of the employee - ");
	gets(person1.name);
	printf("enter the date of joining in dd mm yyyy format - \n");
	scanf("%d %d %d", &person1.day, &person1.month ,&person1.year);
	printf("enter the salary of the employee - ");
	scanf("%f", &person1.salary);
	
	printf("\n\nThe Employee Details:\n");
	printf("Name - %s\nDate of joining - %d-%d-%d\nSalary - %.2f", person1.name, person1.day, person1.month, person1.year, person1.salary);	
} 
