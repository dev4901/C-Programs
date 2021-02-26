#include<stdio.h>

struct test{
	int d1;
	int d2;
};

void input(struct test *d);

int main()
{
	struct test *m,d;
	m=&d;
	input(&d);
	//m=&d;
	printf("d1 is %d\nd2 is %d",d.d1,d.d2);
} 

void input(struct test *d)
{
	struct test t;	
	t.d1=5;
	t.d2=80;
	*d=t;
}

