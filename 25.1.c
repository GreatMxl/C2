#include <stdio.h>
int main() 
{
    if (printf("Hi guys! ") || printf("Xiyou Linux "))    //逻辑或左侧返回值为8,真，触发短路求值
    {
        printf("%d\n", printf("Welcome to Xiyou Linux 2%d", printf("")));
        //printf嵌套调用，由内向外解析，最内层返回值为0,0替代中间层%d，中间层共25个字符
    }
    return 0;
}
//运行结果如下
//Hi guys! Welcome to Xiyou Linux 2025