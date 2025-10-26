#include <stdio.h>
int main(int argc, char* argv[])    //argc:命令行参数，argv:命令行参数数组
{
    printf("argc = %d\n", argc);   //打印程序启动时的argc值
    while (argc++ > 0)    
    //循环会一直执行到argc的递增导致溢出（对于有符号整数，溢出后可能变为负数）
    //但这是未定义行为，实际中循环会执行很多次 
    {
        if(argc < 0)  //argc至少为1（程序本身），条件永远不成立，不会后续打印和break
           printf("argv[0] %s\n", argv[0]);
           break;
    }
    printf("argc = %d\n", argc);   //最终打印溢出后的数
    return 0;
}
//运行结果如下
//argc = 1
//argc = -2147483648