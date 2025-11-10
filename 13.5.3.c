#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    FILE *fp;
    char filename[80];
    char ch;
    printf("input teh filename:");
    scanf("%s",filename);
    if((fp=fopen(filename,"r+"))==NULL)
    {
        printf("can not open file %s.\n",filename);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
    {
        fseek(fp,-sizeof(char),SEEK_CUR);
        putc(toupper(ch),fp);
    }
    fclose(fp);
    return 0;
}
