#include<stdio.h>
#include<conio.h>

int main()
{
	void pr(float a[], int b);
	int b;
	float a[3]={1.1,2.2,3.3};
	b=3;
	pr(a,3);
	getch();
}

void pr(float a[], int b)
{
	int i;
	for(i=0;i<b;i++)
		printf("%f ",a[i]);
	return;
}
