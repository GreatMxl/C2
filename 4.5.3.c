#include <stdio.h>
int main()
{
    float input;
    printf("Enter a float number:");
    scanf("%f",&input);
    printf("The input is %.1f or %.1e \n",input,input);
    return 0;
}