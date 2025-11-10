#include <stdio.h>
static int count=0;
int run_counter (void);
int main()
{
    for(int i=0;i<=100;i++)
        printf("zhe function run_time run %d times\n",run_counter()); 
}
int run_counter(void)
{
    return ++count;
}