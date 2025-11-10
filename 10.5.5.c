#include <stdio.h>
double get_range(double number[],int n);
int main()
{
    double source[12];
    printf("the max diff in arr is %g",get_range(source,12));
    return 0;
}
double get_range(double number[],int n)
{
    double max=number[0];
    double min=number[0];
    for(int i=0;i<n;i++)
    {
        if(max<number[i])
           max=number[i];
        if(min>number[i])
           min=number[i];
    }
    return max-min;
}