#include <stdio.h>
int main() 
{
    int a[3] = { 2, 4, 8 };
    int(*b)[3] = &a;
    int* c[3] = { a, a + 1, a + 2 };
    int (*f1(int))(int*, int);   //f1参数为一个 int* 指针和一个 int，返回值为 int
    printf("a 的地址: %p\n", (void*)a);            //a=数组a的首地址
    printf("*b 的地址: %p\n", (void*)*b);          //*b=a=数组a的首地址
    printf("*b + 1 的地址: %p\n", (void*)(*b + 1));//*b+1=a数组第二元素的地址
    printf("c 的地址: %p\n", (void*)c);            //c=指向c[0]的二级指针（c[0]是指向a[0]的指针，双层解引用
    printf("*(*b + 1) 的值: %d\n", *(*b + 1));     //*(*b+1)=a数组第二元素的值
    printf("sizeof(a): %zu\n", sizeof(a));        //sizeof(a)=数组a总大小=3*4
    printf("sizeof(b): %zu\n", sizeof(b));        //sizeof(b)=数组指针b的大小    64位系统中地址大小为8字节
    printf("sizeof(&a): %zu\n", sizeof(&a));      //sizeof(&a)=数组地址&a的大小  同上
    printf("sizeof(f1): %zu\n", sizeof(&f1));     //sizeof(f1)=函数指针&f1的大小 同上
    return 0;
}
//运行结果如下
//a 的地址: 0x7fffffffdaf4
//*b 的地址: 0x7fffffffdaf4
//*b + 1 的地址: 0x7fffffffdaf8
//c 的地址: 0x7fffffffdb00
//*(*b + 1) 的值: 4
//sizeof(a): 12
//sizeof(b): 8
//sizeof(&a): 8
//sizeof(f1): 8