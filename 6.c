#include <stdio.h>
struct P 
{
    int x;   // 普通int成员，可修改
    const int y;   //const int成员，初始化后不可修改
};

int main() 
{
    struct P p1 = { 10, 20 }, p2 = { 30, 40 };   //1和p2是普通结构体变量，其x可修改，但y一旦初始化后不可修改
    const struct P p3 = { 50, 60 };   //常结构体，整个结构体对象不可修改（包括x）
    struct P* const ptr1 = &p1;   //常指针,指针本身的地址不可修改，可修改所指结构体的非const成员(x)
    const struct P* ptr2 = &p2;   //常结构体，指针本身的地址可修改，不能修改所指结构体的任何成员
    const struct P* const ptr3 = &p3;   //常结构体，常指针，本身地址不可修改，不可修改结构体
    return 0;
}
//题目答案如下
//ptr1->x = 100:合法
//ptr1->y = 200:不合法
//ptr1 = &p2:不合法
//ptr2->x = 300:不合法
//ptr2->y = 400:不合法
//ptr2 = &p1:合法
//ptr3->x = 500:不合法
//ptr3->y = 600:不合法
//ptr3 = &p1:不合法
