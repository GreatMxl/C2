#include <stdio.h>
double min(double x,double y)
{
    if(x<y)
       return x;
    else 
       return y;
}
int main()
{
    double d1,d2;
    printf("input 2 float number:");
    scanf("%1f %1f",&d1,&d2);
    printf("the min of the two number is %d",min(d1,d2));
}