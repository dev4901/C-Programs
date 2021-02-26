#include<stdio.h>

struct structure
{
	int mem1;
	float mem2;
	struct
	{
		int mem3;
		int mem4;
	}members;
	int mem5;
};

int main()
{
	struct structure s1={24,23,45,46,29};
	printf("value of mem3 and mem4 are - \n %d %d\n",s1.members.mem3,s1.members.mem4);
} 
