#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    int ch;
    FILE  *fp;
    unsigned long count =0;
    char filename[50];
    printf("please input the file name:");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL);
    {
        printf("can not open %s",filename);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("file %s has %1u charactera\n",filename,count);
    return 0;
}
