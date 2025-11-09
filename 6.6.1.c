#include <stdio.h>
int main()
{
    char arr[26];
    int i;
    char c='a';
    for (i=0;i<26;i++,c++)
        arr[i]=c;
    for (i=0;i<26;i++)
        printf("%c",arr[i]);
    return 0;
}