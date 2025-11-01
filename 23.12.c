#include <stdio.h>
struct structure 
{
    int foo;  //4字节
    union 
    {
      int integer;
      char string[11];  //11字节
      void *pointer;
    } node;  //共用体，成员共享内存，大小取决于最大成员，共用体node的起始地址紧跟在foo之后，即从结构体的第 4 字节开始
    short bar;  //2字节
    long long baz;  //8字节
    int array[7];  //28字节
};
int main(void) 
{
    int arr[] = {0x590ff23c, 0x2fbc5a4d, 0x636c6557, 0x20656d6f,  //前4字节为foo，node.string从arr[1]到arr[3]的部分数据在string中存储
//arr[2]=0x636c6557→内存中为57 65 6c 63；arr[3]=0x20656d6f→内存中为6f 6d 65 20（取前3字节）
                 0x58206f74, 0x20545055, 0x6577202c, 0x6d6f636c,
                 0x6f742065, 0x79695820, 0x4c20756f, 0x78756e69,
                 0x6f724720, 0x5b207075, 0x33323032, 0x7825005d,
                 0x636c6557, 0x64fd6d1d};
    printf("%s\n", ((struct structure *)arr)->node.string);  //数组arr被强制转换为struct structure*，因此arr的元素会按内存布局填充结构体成员
    //将上述 11 字节转换为 ASCII 字符，最终输出结果
}
//运行结果如下
//Welcome