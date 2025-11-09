#include <stdio.h>
int main()
{
    char ch;
    int counter=0;
    printf("please input chars(# as end)");
    while((ch=getchar())!='#')
    {
        if(counter++%8==0)
          printf("\n");
        if(ch=='\n')
          printf("'\\n'-%03d. ",ch);
        else if(ch=='\t')
          printf("'\\t'-%03d. ",ch);
        else printf("'%c'-%03d. ",ch,ch);
    }
    printf("done");
    return 0;
}