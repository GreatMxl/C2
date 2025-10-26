#include <stdio.h>
int g;   //全局变量，初始化为0
int func() 
{
    static int j = 98;   //静态局部变量，初始化一次，每次调用保留上次调用后的值
    j += g;
    return j;
}

int main() 
{
    g += 3;   //g的值更新为3
    char arr[6] = {};
    arr[1] = func();   //第1次调用，返回101,ASC2码对应为e，数组第2元素储存为e
    arr[0] = func();   //第2次调用，返回104,ASC2码对应为h，数组第1元素储存为h
    arr[2] = arr[3] = func() + 1;   //第3次调用，返回108,ASC2码对应为l，数组第3,4元素储存为l
    arr[4] = func() + 1;   //第4次调用，返回110,ASC2码对应为0，数组第5元素储存为o
    printf("%s linux\n",arr);
    return 0;
}
//运行结果如下
//hello linux