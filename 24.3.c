#include <stdio.h>
int main() 
{
    float a = 1.0, b = 1.1, ex = 0.1;
    printf("b - a == ex is %s\n", (b - a == ex) ? "true" : "false");  //浮点数在计算机中进行二进制存储，存在精度误差
    int A = a * 10, B = b * 10, EX = ex * 10;
    printf("B - A == EX is %s\n", (B - A == EX) ? "true" : "false");  //整数的存储精确
}
//运行结果如下
//b - a == ex is false
//B - A == EX is true