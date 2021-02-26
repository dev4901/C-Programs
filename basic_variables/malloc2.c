#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i,d,garb;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    for(i = 0 ; i < num; i++)
    {
        d=num - 1 - i;
        garb = *(arr + i);
        *(arr + i) = *(arr + d);
        *(arr + d) =  garb;
    }   


    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));

}

