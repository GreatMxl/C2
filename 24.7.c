#include <stdio.h>
int main(int argc, char *argv[]) 
{
    while (argc++ > 0);  //argc先判断是否大于0,再自增，增大到某一个值会溢出变为极小的负数，循环因此终止
    int a = 1, b = argc, c = 0;
    if (--a || b++ && c--)  //a先自减为0,假，进行||右侧操作，b为极小的负数,为真；c=0,为假，故整体表达式为假，不会执行后续程序
        for (int i = 0; argv[i] != NULL; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    printf("a = %d\nb = %d\nc = %d\n", a, b, c);
    return 0;
}
//运行结果如下
//a = 0
//b = -2147483646
//c = -1