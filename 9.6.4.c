#include <stdio.h>
double average(double x,double y)
{
    return 2/(1/x+1/y);
}
int main()
{
    double d1,d2;
    printf("input two float number:");
    scanf ("%1f %1f",&d1,&d2);
    printf("the average of two numbwer is %g",average(d1,d2));
}