#include <stdio.h>
double cublic(double n);
int main()
{
    double input;
    printf("enter the double datum to calc cublic:");
    scanf ("%1f",&input);
    cublic(input);
    printf("program exit!");
    return 0;
}
double cubic(double n)
{
    double t=n*n*n;
    printf("the %1g is %1g!",n,t);
    return t;
}