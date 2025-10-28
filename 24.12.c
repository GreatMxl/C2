#include <stdio.h>
#include <ctype.h>
union data  //联合体 union data
{
    int a;
    double b;  //联合体所有成员共享同一块内存空间，大小由最大成员（double b，8字节）决定
    short c;
};
typedef struct node  //结构体 Node
{
    long long a;
    union data b;  //联合体成员（8 字节）
    void (*change)(struct node *n);  //函数指针（通常 8 字节，与平台相关）
    char string[0];  //柔性数组（不占用结构体空间，用于动态扩展存储字符串)
} Node;
void func(Node *node)   //将 Node 结构体中 string 成员的所有字符转换为小写
{
    for (size_t i = 0; node->string[i] != '\0'; i++)  //环遍历字符串，使用 tolower 函数转换每个字符
        node->string[i] = tolower(node->string[i]);
}

int main() 
{
    const char *s = "WELCOME TO XIYOULINUX_GROUP!";
    Node *P = (Node *)malloc(sizeof(Node) + (strlen(s) + 1) * sizeof(char));  //动态分配内存:sizeof(Node)+字符串长度+1（+1用于存储字符串结束符 \0）
    strcpy(P->string, s);  //将字符串复制到柔性数组 string 中
    P->change = func;  //给函数指针 change 赋值为 func
    P->change(P);  //调用 P->change(P) 执行转换
    printf("%s\n", P->string);  //输出转换后的小写字符串
    return 0;
}
//运行结果如下
//welcome to xiyoulinux_group!