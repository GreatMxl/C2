#include <stdio.h>
int main(void)
{
    char name[40];
    int a;
    printf("Please input your name:");
    scanf("%s",name);
    a=printf("\"%s\".\n",name);
    a-=4;
    printf("\"%20s\".\n",name);
    printf("\"%-20s\".\n",name);
    printf("\"%*s\"",(a+3),name);
}