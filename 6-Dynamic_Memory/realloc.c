#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *buff = calloc(10, sizeof(char));
    if (buff == NULL)
    {
        printf("memory alloc failed");
        exit(1);
    }
    printf("buffer of size %ld bytes created \n", sizeof(buff));
    strcpy(buff, "ABCDEFGHIJ");
    printf("value in buff is %s\n", buff);
    buff = realloc(buff, 15);
    if (buff == NULL)
    {
        printf("memory alloc failed");
        exit(1);
    }
    printf("value in buff after reallocation %s\n", buff);
    strcpy(buff, "abcdefghijklmno");
    printf(" new value in buff is %s\n", buff);
}
