#include<stdio.h>
int main()
{
    int counter=0;
    char ch;
    printf("please input chars(# as end):");
    while((ch=getchar())!='#')
    {
        switch(ch)
        {
            case'!':
                printf("!!");
                counter++;
                break;
            case'.':
                printf("!");
                counter++;
                break;
            default:
                printf("%c",ch);
        }
    }
    printf("\ntotle replace %d times\n",counter);
    return 0;
}