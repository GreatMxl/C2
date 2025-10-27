#include <stdio.h>
int main() 
{
    unsigned int a = 2024;   //a为unsigned int类型，是无符号整数，永远大于等于0
    for (; a >= 0; a--)  //因此a》=0条件永远成立，无限循环
        printf("%d\n", printf("Hi guys! Join Linux - 2%d", printf("")));  //printf嵌套，有内向外解析，
        //最内层解析为0,取代第二层%d，第二层共24个字符，最外层解析为24,
    return 0;
}
//运行结果为
//Hi guys! Join Linux - 2024\n的无限循环