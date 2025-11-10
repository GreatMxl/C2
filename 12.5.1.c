#include<stdio.h>
void critic (int*n);
int main()
{
    int units;
    printf("how many pounds?\n");
    scanf("%d",&units);
    while(units!=56)
         critic(&units);
    printf("you must have looked it up!\n");
    return 0;     
}
void critic(int* n)
{
    printf("no lucky, my friends,try again\n");
    scanf("%d\n");
}