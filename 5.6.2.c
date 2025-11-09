#include <stdio.h>
int main(int argc,char *argv[])
{
    int counter,i=0;
    printf("print continue 10 numbers!\n");
    scanf("%d",&counter);
    while(i++<11)
    {
        printf("%d\n",counter++);
    }
    printf("program exit!\n");
    return 0;
}