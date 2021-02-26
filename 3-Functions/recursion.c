#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
int i=3;
int find_nth_term(int n, int a, int b, int c);

int find_nth_term(int n, int a, int b, int c) 
{
    int nterm;
    static int s[21];
   // static int i;
    s[0]=a; s[1]=b; s[2]=c;
    if (n>=4 && i<=(n-1)) 
    {
        s[i]=s[i-1]+s[i-2]+s[i-3];
        i++;
        nterm=find_nth_term(n,a,b,c);
        return 1;
    }
    else 
        return s[n-1];
    
}


int main() {
    int n, a, b, c,ans;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}
