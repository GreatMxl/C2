#include <stdio.h>
struct Student 
{
    char *name;
    int age;
};

void initializeStudent(struct Student *student, const char *name, int age) 
{
    student->name = (char *)malloc(strlen(name) + 1);//strlen(name) 计算传入字符串 name 的长度，+1为 \0 预留一个字节空间
    //malloc(...) 从堆内存中分配指定大小的字节空间，返回 void* 指针，通过 (char *) 强制转换为字符指针，赋值给 student->name（让结构体的 name 指针指向这块新分配的内存）
    strcpy(student->name, name);//strcpy字符串复制函数，将参数name指向的字符串（包括 \0）复制到 student->name 指向的内存中（即上一步分配的堆内存）。
    student->age = age;  //整数赋值，无内存分配问题
}
int main(void) 
{
    struct Student s1, s2;
    initializeStudent(&s1, "Tom", 18);
    initializeStudent(&s2, "Jerry", 28);
    s1 = s2;  //结构体的浅拷贝，s1和s2都是struct Student类型，赋值时会将s2的成员逐个复制给s1
    //对于指针成员name，复制的是指针的值（内存地址），而非指针指向的字符串内容，因此，赋值后 s1.name 和 s2.name 会指向同一块堆内存（"Jerry" 所在的内存）
    printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
    printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
    free(s1.name);
    free(s2.name);  //第二次 free 操作会导致双重释放，会破坏堆内存管理的完整性，导致程序崩溃或其他不可预测的行为
    return 0;
}
//修改程序如下
//int main(void) 
//{
//    struct Student s1, s2;
//    initializeStudent(&s1, "Tom", 18);
//    initializeStudent(&s2, "Jerry", 28)；

//    free(s1.name);  //手动深拷贝，避免指针共享，先释放s1原来的内存
//    s1.name = (char *)malloc(strlen(s2.name) + 1);  // 重新分配内存
//   strcpy(s1.name, s2.name);  // 拷贝内容
//    s1.age = s2.age;  // 复制年龄

//    printf("s1的姓名: %s 年龄: %d\n", s1.name, s1.age);
//    printf("s2的姓名: %s 年龄: %d\n", s2.name, s2.age);
//    free(s1.name);  // 释放各自的内存，无重复
//    free(s2.name);
//   return 0;
//}