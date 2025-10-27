#include <stdio.h>
int main(int argc, char **argv) 
{
    int a = 1, b = 2;
    const int *p = &a;  //指向常量的指针p，其所指内容不可修改
    int * const q = &b;  //常量指针q，其本身地址不可修改
    //*p = 3, q = &a; //均错误，均不可被修改
    const int * const r = &a;  //指向常量的常量指针r
    //*r = 4, r = &b;  均错误，均不可被修改
    return 0;
}