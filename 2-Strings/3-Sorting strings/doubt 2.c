#include<stdio.h>
int k;
int main()
{
	int var,n; 
	int d[k];
	scanf("%f %d",&n,&k);
	for(var=1;var<=n;var+=1)
	{
		var=d[(var-1)];
		printf("%d",d[var]);
	}
	return 0;
}
