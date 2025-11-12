#include <stdio.h>
#define average(x,y)(2/(1/x+1/y))
int main()
{
    double a,b;
    printf("please input two float number:");
    scanf("%1f %1f",&a,&b);
    printf("the average of %1f and %1f is %1f",a,b);
}