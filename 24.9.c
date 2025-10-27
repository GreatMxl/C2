#include <stdio.h>
#define SQUARE(x) ((x) *x)  //宏定义，计算x的平方
#define MAX(a, b) ((a > b) ? a : b)  //返回a，b中的最大值
#define PRINT(x) printf("嘻嘻，结果你猜对了吗，包%d滴\n", x);
#define CONCAT(a, b) a##b  //将a，b连接成一个标识符

int main() 
{
    int CONCAT(x, 1) = 5;  //x1=5
    int CONCAT(y, 2) = 3;  //y2=3
    int max = MAX(SQUARE(x1 + 1), SQUARE(y2));  //36,9，返回36
    PRINT(max);
    return 0;
}
//运行结果如下
//嘻嘻，结果你猜对了吗，包36滴