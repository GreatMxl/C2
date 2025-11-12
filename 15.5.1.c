#include <stdio.h>
#include <stdlib.h>
#define size 32
int main ()
{
    char input[size];
    printf("enter a binary string");    
    scanf("%d\n",input);
    printf("%d\n",bstoi(input));
    return 0;
}
int bstoi(char *st)
{
    int sum=0;
    while(*st!='\0')
    {
        sum *=2;
        sum+=*st++ -'\0';
    }
    return sum;
}