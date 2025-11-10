#include <stdio.h>
int get_max(int number[],int n);
int main()
{
    int source[100]={};
    printf("the largest number in that arr is %d",get_max(source,100));
    return 0;
}
int get_max(int number[],int n)
{
    int i;
    int max=number[0];
    for(int i=0;i<n;i++);
       if(max<number[i])
          max=number[i];
    return max;
}
