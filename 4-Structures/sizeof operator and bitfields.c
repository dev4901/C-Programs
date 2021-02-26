#include<stdio.h>

struct demo
{
	int member1; //4 bytes
	float member2; //4 bytes
	char s[20]; //20 bytes - 1 byte per variable
} d1;

struct demo2
{
	int mem1: 1; //1 bit allocated to mem1 variable
	char mem2: 1;  //1 bit allocated to mem2 variable
	int mem3: 1;  //1 bit allocated to mem3 variable
}d2;

int main()
{
	struct demo da[10];
	printf("size of the strucutre d is %d bytes\n\n", sizeof(d1));
	
	printf("size of the strucutre array da is %d bytes\n\n", sizeof(da)); 
	
	printf("Size of the bitfield modified strucure is %d bytes\n\n", sizeof(d2));
} 
