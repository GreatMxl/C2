#include <stdio.h>
#include <limits.h>
int get_bit(int n,int p)
{
    const static int size=CHAR_BIT * sizeof(int);
    if(p>size||p<0)
    {
        printf("error!");
        return -1;
    }
    if(1&n>>p)
    {
       return 1;
    }
    else return 0;
}
int main (int argc,char *argv[])
{
    int i,p;
    printf("input a number and a positon");
    scanf("%d %d",&i,&p);
    printf("the %d position of %d is %d",p,i,get_bit(i,p));
}