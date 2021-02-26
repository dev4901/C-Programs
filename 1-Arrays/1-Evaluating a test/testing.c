 #include<stdio.h>
 #define que 5
/*there will be 5 questions in the test*/
/*enter the input continuously wihtout any space in between*/
int main()
{
	char key[8];
	char response[8];
	int i,j,wrong,mark,numstd,k;
	j=mark=wrong=i=0;
	k=1;
	/*code for entering the answer key*/
	printf("enter the key value - \n");
	for(i=0;i<que;i++)
	{
		scanf("%c",&key[i]);
    }
    scanf("%c",&key[5]);
	//key[5]=getchar();
    /*entering of key is over*/
	/*now for each student their marks will be calculated*/

	printf("enter the number of students - ");
	scanf("%d",&numstd);
	for(k=1;k<=numstd;k++)
	{
		printf("\nStudent no. - %d",k);
		/*entering of responses of the respective student*/
		mark=i=wrong=j=0;
		printf("\n enter the response value - \n");
		for(j=0;j<que;j++)
		{
			//response[j]=getchar();
			scanf("%c",&response[j]);
		}
		scanf("%c",&response[5]);
		//response[5]=getchar();
		/*comparing the key with the responses and calculating the marks*/
		for(i=0;i<que;i++)
		{	    
	    	if(key[i]==response[i])
			{
				mark+=1;
				//continue;
			}
			else 
			{
				wrong+=1;
				//continue;
			}
		}
			printf("\n mark = %d",mark);
			printf("\n wrong = %d",wrong);
  	}
}
