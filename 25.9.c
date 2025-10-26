#include <stdio.h>
#define CALL_MAIN(main, x) (*(int (*)(int))*main)(x); 
//宏定义，将main函数解引用得到函数指针（*main），转换为 int (*)(int) 类型
//（接收 int 参数、返回 int 的函数指针），再调用main并传入参数 x
#define DOUBLE(x) 2 * x   //宏定义，计算x的2倍
int (*registry[1])(int);  //包含 1 个元素的函数指针数组，每个元素都是int (*)(int)类型（接收 int 参数并返回 int 的函数指针）
int main(int argc) 
{
    if (argc > 2e3)    //2000
    return 0;   
    printf("%d ", argc + 1);
    *registry = (int(*)(int))main;  //将main函数自身的地址存入registry数组    
    CALL_MAIN(registry, DOUBLE(argc + 1));  //通过CALL_MAIN宏递归调用main，传入参数为2*(argc+1)
    return 0;
}
//运行结果如下
//2 4 8 16 32 64 128 256 512 1024

