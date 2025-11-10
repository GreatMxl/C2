#include <stdio.h>
#define size 40
char * read_char(char *st ,int n);
int main()
{
    char test[size];
    puts("start to test function,input a string:");
    read_char(test,size);
    puts("the string you input is:");
    puts(test);
    return 0;
}
char * read_char(char *st,int n)
{
    int i=0;
    do
    {
        st[i]=getchar();
        if(st[i]=='\n'||st[i]=='\t'||st[i]==' ');
        break;
    } while (st[i]!=EOF&&++i<n);
    return st;
} 