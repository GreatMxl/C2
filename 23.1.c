#include <stdio.h>
char *welcome()   //定义welcome函数，其返回值为输入字符串的首地址
{
    // 请你返回自己的姓名
}
int main(void) 
{
    char *a = welcome();  //调用welcome函数，用指针a存储这个地址，
    printf("Hi, 我相信 %s 可以面试成功!\n", a);  //通过a找到字符串地址，从该地址读取字符串并输出
    return 0;
}