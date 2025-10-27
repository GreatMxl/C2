#include <stdio.h>
int main(int argc, char *argv[]) 
{
    while (argc++ > 0);  //先判断，再自增，大于某一个数后溢出变为极小的负数，终止循环
    int a = 1, b = argc, c = 0;
    if (--a || b++ && c--)  //逻辑或左侧为0,假，进行右侧判断，b非0为真；c=0为假，故表达式为假，不进行下述程序
        for (int i = 0; argv[i] != NULL; i++)
            printf("argv[%d] = %s\n", i, argv[i]);
    printf("a = %d\nb = %d\nc = %d\n", a, b, c);
    return 0;
}
//运行结果如下
//a = 0
//b = -2147483646
//c = -1