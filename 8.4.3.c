#include <stdio.h>
#include <ctype.h>
int main()
{
    int lc=0;
    int uc=0;
    char ch;
    while((ch=getchar())!=EOF)
    {
        if (ch>='a'&&ch<='z')
           lc++;
        if (ch>='A'&&ch<='Z')
           uc++;
    }
    printf("there are %d lowercase,there are %d uppercase",lc,uc);
    return 0;
}
