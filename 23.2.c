#include <stdio.h>
int main(void) 
{
    char *ptr0 = "Welcome to Xiyou Linux!";
    char ptr1[] = "Welcome to Xiyou Linux!";
    if (*ptr0 == *ptr1)  //均表示字符串第一个字符“W”，条件为真，进入分支
    {
      printf("%d\n", printf("Hello, Linux Group - 2%d", printf("")));
      //printf("")为空字符串，表示0，取代%d，输出23个字符，返回23接到中间层返回值最后
    }
    int diff = ptr0 - ptr1;  //两个地址的数值差
    printf("Pointer Difference: %d\n", diff);
}
//运行结果如下
//Hello, Linux Group - 2023                                                                                                   
//Pointer Difference: -2473504