#include <stdio.h>
int main() 
{
    int a[2] = {4, 8};
    int(*b)[2] = &a;  //数组指针
    int *c[2] = {a, a + 1};  //指针数组
    //a
    printf("a = %p\n", (void*)a);               // &a[0]
    printf("a + 1 = %p\n", (void*)(a + 1));     // &a[1]
    printf("&a = %p\n", (void*)&a);             // 整个数组的地址
    printf("&a + 1 = %p\n", (void*)(&a + 1));   // 数组地址+1（跳过整个数组，偏移量为2*sizeof(int)）
    printf("*(a + 1) = %d\n", *(a + 1));        // a[1] = 8
    printf("sizeof(a) = %zu\n", sizeof(a));     // 数组总大小（2*sizeof(int)，通常为8字节）
    printf("sizeof(&a) = %zu\n\n", sizeof(&a)); // 数组指针的大小（64位系统8字节）
    //b
    printf("*b = %p\n", (void*)*b);             // a
    printf("*b + 1 = %p\n", (void*)(*b + 1));   // a+1
    printf("b = %p\n", (void*)b);               // &a
    printf("b + 1 = %p\n", (void*)(b + 1));     // 同&a+1，跳过整个数组
    printf("*(*b + 1) = %d\n", *(*b + 1));      // a[1] = 8
    printf("sizeof(*b) = %zu\n", sizeof(*b));   // 解引用后数组的大小（同sizeof(a) = 8字节）
    printf("sizeof(b) = %zu\n\n", sizeof(b));   // 指针变量b的大小（同sizeof(&a)）
    //c
    printf("c = %p\n", (void*)c);               // 指针数组c的首地址
    printf("c + 1 = %p\n", (void*)(c + 1));     // 指针数组c的第二个元素地址（偏移量为sizeof(int*)）
    printf("&c = %p\n", (void*)&c);             // 整个指针数组c的地址（类型为int*(*)[2]）
    printf("&c + 1 = %p\n", (void*)(&c + 1));   // 指针数组地址+1（跳过整个数组，偏移量为2*sizeof(int*)）
    printf("**(c + 1) = %d\n",**(c + 1));       // a[1] = 8
    printf("sizeof(c) = %zu\n", sizeof(c));     // 指针数组总大小（2*sizeof(int*)，通常为16字节）
    printf("sizeof(&c) = %zu\n", sizeof(&c));   // 指针数组指针的大小（同其他指针，8字节或4字节）
    return 0;
}
//运行结果如下
//a = 0x7fffffffdaf8
//a + 1 = 0x7fffffffdafc
//&a = 0x7fffffffdaf8
//&a + 1 = 0x7fffffffdb00
//*(a + 1) = 8
//sizeof(a) = 8
//sizeof(&a) = 8

//*b = 0x7fffffffdaf8
//*b + 1 = 0x7fffffffdafc
//b = 0x7fffffffdaf8
//b + 1 = 0x7fffffffdb00
//*(*b + 1) = 8
//sizeof(*b) = 8
//sizeof(b) = 8

//c = 0x7fffffffdb00
//c + 1 = 0x7fffffffdb08
//&c = 0x7fffffffdb00
//&c + 1 = 0x7fffffffdb10
//**(c + 1) = 8
//sizeof(c) = 16
//sizeof(&c) = 8