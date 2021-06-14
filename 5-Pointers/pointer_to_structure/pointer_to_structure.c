#include <stdio.h>

struct student
{
	char name[20];
	int age;
};

int main()
{
	struct student s1, *s;
	s = &s1;
	printf("taking input using the arrow operator:\nEnter a name and age- ");
	scanf("%s %d", s->name, &s->age);
	printf("name - %s and age - %d", s->name, s->age);
	printf("\n\ntaking input using dot operator:\nEnter name and age - ");
	scanf("%s %d", (*s).name, &(*s).age);
	printf("name - %s and age - %d/n", (*s).name, (*s).age);
}
