#include <stdio.h>
int main()
{
    char ch;
    int blank=0;
    int others=0;
    int endline=0;
    printf("please input chars(# as end):");
    while(ch=getchar()!='#')
    {
        if(ch==' ')
           blank++;
        else if(ch=='\n')
           endline++;
        else others++;
    }
    printf("%d blank,%d endline,%d others",blank,endline,others);
    return 0;
}