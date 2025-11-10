#include <stdio.h>
#include <ctype.h>
int main()
{
    int words;
    int letter;
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(isalpha(ch)!=0)
            letter++;
        if(ispunct(ch)!=0)
            words++;
    }
    printf("there are %d words,there are %d letter",words,letter);       
}