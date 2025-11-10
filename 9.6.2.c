#include <stdio.h>
void chline(char ch,int cols,int rows)
{
    for (int m=0;m<rows;m++)
    {
        for(int n=0;n<cols;n++)
            printf("%c\n",ch);
        printf("\n");    
    }
}
int main()
{
    char c;
    int i,j;
    printf("input the char you want to print:");
    scanf("%c",&c);
    printf("input the rows and cols you want to print:");
    scanf("%d %d",&j,&i);
    chline(c,i,j);
    return 0;
}
