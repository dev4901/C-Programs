#include<stdio.h>
#include<stdlib.h>

struct abc{
	int x;
	int y;
};


int main()
{
	int choose;
	printf("Choose any one of the following:\n");
	printf("1. predefined values of the array.\n2. Input the values for each struct ");
	printf("\nEnter the option number: ");
	scanf("%d",&choose);
	printf("\n");
	switch(choose){
		case 1: ;
			struct abc arr[3]={{1,7},{3,5},{91,22}},*s;
			s=arr;
			/*arr[0]={1,7};
			*(s)={1,7};
			*(s+1)={3,5};
			*(s+2)={91,22};
			*/
			printf("value of 1st struct is %d and %d\n",s->x,s->y);
			printf("value of 2nd struct is %d and %d\n",(s+1)->x,(s+1)->y);
			printf("value of 3rd struct is %d and %d\n",(s+2)->x,(s+2)->y);
			break;
		case 2: ;
			struct abc arr2[3],*s2=malloc(3*sizeof(struct abc));
			//s2=arr2;
			printf("enter value of index 0 element - ");
			scanf("%d %d",&s2->x,&s2->y);
			printf("\nenter value of index 1 element - ");
			scanf("%d %d",&(s2+1)->x,&(s2+1)->y);
			printf("\nenter value of index 2 element - ");
			scanf("%d %d",&(s2+2)->x,&(s2+2)->y);
			printf("\nvalue of index 0 element - %d %d",s2->x,s2->y);
			printf("\nvalue of index 1 element - %d %d",(s2+1)->x,(s2+1)->y);
			printf("\nvalue of index 2 element - %d %d\n",(s2+2)->x,(s2+2)->y);	
			break;
		default:
			printf("Run it again Bitch\nnext time enter a vald number! \n or you'll have to run it again.");
	}
	//this is for pre-defined values of the array
	/*struct abc arr[3]={{1,7},{3,5},{91,22}},*s;
	s=arr;
	//arr[0]={1,7};
	//*(s)={1,7};
	//*(s+1)={3,5};
	//*(s+2)={91,22};
	printf("value of 1st struct is %d and %d\n",s->x,s->y);
	printf("value of 2nd struct is %d and %d\n",(s+1)->x,(s+1)->y);
	printf("value of 3rd struct is %d and %d\n",(s+2)->x,(s+2)->y); */
	
	//now this is for taking input of array values from the user
	/*struct abc arr[3],*s;
	s=arr;
	printf("enter value of index 0 element - ");
	scanf("%d %d",&s->x,&s->y);
	printf("\nenter value of index 1 element - ");
	scanf("%d %d",&(s+1)->x,&(s+1)->y);
	printf("\nenter value of index 2 element - ");
	scanf("%d %d",&(s+2)->x,&(s+2)->y);
	printf("\nvalue of index 0 element - %d %d",s->x,s->y);
	printf("\nvalue of index 1 element - %d %d",(s+1)->x,(s+1)->y);
	printf("\nvalue of index 2 element - %d %d",(s+2)->x,(s+2)->y);	
	*/
	
}
