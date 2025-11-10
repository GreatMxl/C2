#include <stdio.h>
char get_first();
int main()
{
    char ch;
    ch=get_first();
    printf("%c\n",ch);
}
char get_first()
{
    char ch;
    do
    {
        ch=getchar();
    } while (ch==' '||ch=='\n'||ch=='\t');
    return ch;
}