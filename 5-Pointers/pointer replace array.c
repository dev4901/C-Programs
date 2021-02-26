#include<stdio.h>
#include<conio.h>
int main()
{
 int *ptr1,a,i,*ptr2;
 ptr2=&a;
 ptr1=ptr2;
 i=0;
 while(i==0)
 {
 	scanf("%d",ptr2);
 	if(*ptr2==-1)
 		break;
 	else
 		ptr2++;
 }
 i=ptr2-ptr1; 
 //ptr1=ptr2;
 printf("\n");
 while(ptr1<=ptr2)
 {
 	printf("%d, ",*ptr1);
 	ptr1++;
 }
 printf("total number of values are %d",i);
 
} 
