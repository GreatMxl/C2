#include <stdio.h>
int main() 
{
    float a1 = 0.3, b1 = 6e-1, sum1 = 0.9;   //这些数值在二进制浮点数中无法精确表示（存在无限循环的二进制小数），导致存在微小误差
    printf("a1 + b1 %s sum1\n", (a1 + b1 == sum1) ? "==" : "!="); 
    float a2 = 0x0.3p0, b2 = 0x6p-4, sum2 = 0x0.9p0;   //这些数值能被二进制浮点数精确表示，故完全相等
    printf("a2 + b2 %s sum2\n", (a2 + b2 == sum2) ? "==" : "!=");
    return 0;
}
//运行结果如下
//a1 + b1 != sum1
//a2 + b2 == sum2