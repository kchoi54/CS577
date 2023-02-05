#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    int num, i;
    char str[40][40];


    //read number
    scanf("%d", &num);

    //flush \n
    fgets(str[0],2,stdin);

    //scan words
    for(i=0; i<num; i++)
    { fgets(str[i], 50, stdin); }

    //print hello
    for(i=0; i<num; i++)
    { printf("Hello, %.*s!\n", (int) strcspn(str[i], "\n"), str[i]); }

    return 0;
}