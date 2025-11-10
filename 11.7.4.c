#include <stdio.h>
#include <ctype.h>
#define size 80
char * get_word(char *out,int n);
int main()
{
    char output[size];
    get_word(output,size);
    printf("first word you inout is:%s",output);
    return 0;
} 
char * get_word(char *out,int n)
{
    char input[size];
    char *in=input;
    int i=0;
    puts("input a string:");
    fgets (input,size,stdin);
    while((*in=='\n'||*in=='\t'||*in==" ")&& *in!='\0')
         in++;
    while(*in!='\n&&*in'!='\t'&&*in!='\0&&i<n')
    {
        *out++=*in++;
        in++;
    }
    return 0;
}