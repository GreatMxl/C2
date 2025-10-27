#include <stdio.h>
int i = 1;  //全局变量，不受函数内局部变量影响
static int j = 15;  //静态全局变量
int func() 
{
    int i = 10;  //“局部变量” 对 “全局变量” 的屏蔽（隐藏）作用,该函数中对i的操作只作用于函数本身

    if (i > 5) i++;
    printf("i = %d, j = %d\n", i, j);
    return i % j;  //取余运算符，返回11给函数
}
int main()
{
    int a = func();  //a=上述函数返回值=11
    printf("a = %d\n", a);
    printf("i = %d, j = %d\n", i, j);  //打印i时，访问全局变量
    return 0;
}
//运行结果如下
//i = 11, j = 15
//a = 11
//i = 1, j = 15
