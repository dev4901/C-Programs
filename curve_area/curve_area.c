//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

float uplimit,lowlimit;
long int ntrapezoids;
double x;
//double area;

double fx(double x);
double* anyfx(double x,int degree);
double areatrap(float lowlimit, float uplimit, long int ntrapezoids);
void input(void);
//double power(float base,float exp);

int main()
{	
	double area;
	input();
	area = areatrap(lowlimit,uplimit,ntrapezoids);
	printf("\n\nArea under the curve is %lf\n\n",area);
	
} 

void input(void)
{
	float buffer;
	//printf("enter the polynomial whose area you want to find: ");
	printf("enter the degree of the polynomial whose area you want to find: ");int degree;
	scanf("%d", &degree);
	d
	printf("enter the respective values below\n");
	printf("lower limit - ");
	scanf("%f",&lowlimit);
	printf("upper limit - ");
	scanf("%f",&uplimit);
	printf("no. of trapezoids - ");
	scanf("%ld",&ntrapezoids);
}

double fx(double x)
{
	double y;
	y = pow(x,2.0)+1;
	return(y); 
}

double* anyfx(double x, int degree)
{
	double y,*coeff;
	coeff = (double*)malloc((degree+1)*sizeof(double));
	printf("enter the coefficiants of the variables with power in descending order:\n");
	for(int i=0;i<degree;i++)
	{
		scanf("%d",(coeff+i));
	}
	for(int i=degree;i>=0;i--)
	{
		y+=*(coeff+i)pow(x,i);
	}
	return y;

}

double areatrap(float uplimit, float lowlimit, long int ntrapezoids)
{
	double area,i,j;
	float buffer, width;
	double n2trapezoids;
	area=0;
	if (uplimit < lowlimit)
	{
		buffer = lowlimit;
		lowlimit = uplimit;
		uplimit = buffer;
	}
	x=(double)lowlimit;
	//n2trapezoids = ntrapezoids * ntrapezoids;
	width = (uplimit-lowlimit)/(float)ntrapezoids;
	for(x=(double)lowlimit; x<=((double)uplimit-(double)width); x+=width)
	{
		i=fx(x);
		j=fx(x+width);

		area+=0.5*(i+j)*(double)width;
	}
	return(area);
}

/*double power(float base, float exp)
{
	int i; double value=1;
	if(exp>0)
	for(i=1;i<=exp;i++)
	{
		value *= base;
	}
} */