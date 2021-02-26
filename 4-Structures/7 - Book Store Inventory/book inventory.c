#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>

struct record
{
	char title[50];
	char author[50];
	float price;
	char publisher[20];
	int qtystock;
};

void input(char title[], char author[]);
int lookup(struct record r[], int size, char title[], char author[]	);
void hline(void);

int main()
{
	struct record r[5] ={ {"C Language","Ritche",45.0,"TMH",15}, {"Programing in Java","Kochan",80.5,"Hayden",20},
		{"BASIC","Balagurusamy",100.25,"Jaico",4}, {"COBOL","R D sharma",200.0,"Penguin",5},
		{"Python crash course","zed shaw",300.0,"penguin",27} };
	char title[50];
	char author[50];
	int index, i = 0,qty,check;
	float cost;
	char j[5];
	while (i == 0)
	{
		hline();
		input(title, author); 
		index = lookup(r, 5, title, author);
		if (index != -1)
		{
			printf("\n%s %s %.2f %s\n", r[index].title, r[index].author, r[index].price, r[index].publisher);
			printf("How many copies do you require: ");
			scanf("%d", &qty);
			if (qty <= r[index].qtystock)
			{
				cost = qty * r[index].price;
				printf("\nYour final bill is %f\n", cost);
			}
			else
			{
				printf("The required number of copies are not available right now\n");
			}
		}
		else
		{
			printf("\nThe book you are looking for is not there in our record.\n");
		}
		printf("Do you want any other book?:[Yes/No]\n");
		scanf("%s", j);
		//gets(j);
		check = strcmp(j,"Yes");
		if(j[0]=='Y' || check==0)
		{
			continue;
		}
		else 
		{
			i = 1;
		}
	}
	printf("\n\n Thank you for shopping here. \n\n");
}

void input(char title[], char author[])
{
	int i;
	char c,d;
	printf("\n");
	printf("Enter the title and author name of the book you want\n");
	printf("Enter title: ");
	/*i = 0;
	title[0] = '\0';
	while (title[i] != '\n')
	{
		c = getchar();
		title[i] = c;
		i++;
	}
	title[i-1] = '\0'; */
	//scanf("%s", title);
	gets(title);
	printf("Enter name of the author: ");
	/*i = 0;
	author[0] = '\0';
	while (author[i] != '\n')
	{
		d = getchar();
		author[i] = d;
		i++;
	}
	author[i-1] = '\0'; */
	//scanf("%s", author);
	gets(author);
}

int lookup(struct record r[], int size, char title[], char author[])
{
	int i, index,t,a;
	index = -1;
	for (i = 0; i < size; i++)
	{
		t = strcmp(title, r[i].title);
		a = strcmp(author, r[i].author);
		if (t == 0 && a == 0)
		{
			index = i;
		}
	}
	return(index);
}

void hline(void)
{
	int i;
	for (i = 0; i < 50; i++)
		printf("-");
}
