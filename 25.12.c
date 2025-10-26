#include <stdio.h>
#include <stdlib.h>  // 补充：malloc、free函数需要的头文件
#include <string.h>  // 补充：strcpy、strlen函数需要的头文件

// 定义共用体data：所有成员共用同一块内存空间
union data {
    void**** p;  // 多级void指针（实际未使用，仅占内存）
    char arr[20]; // 字符数组（长度20字节，决定共用体大小为20字节）
};

// 定义结构体Node
typedef struct node {
    int a;                  // 整数成员，用于控制循环退出条件
    union data b;           // 共用体成员（占20字节）
    void (*use)(struct node* n);  // 函数指针，指向func1或func2
    char string[0];         // 柔性数组（零长度数组），用于动态存储字符串
                            // 注：柔性数组不占用结构体本身的内存，需在malloc时额外分配
} Node;

// 函数声明：func2在func1之前被引用，需提前声明
void func2(Node* node);

/**
 * func1：函数指针指向的第一个函数
 * 功能：切换函数指针指向func2，并打印结构体中的字符串
 * @param node：指向Node结构体的指针
 */
void func1(Node* node) {
    node->use = func2;  // 将函数指针切换为func2，下次调用将执行func2
    printf("%s\n", node->string);  // 打印柔性数组中存储的字符串
}

/**
 * func2：函数指针指向的第二个函数
 * 功能：切换函数指针指向func1，将a递增后打印
 * @param node：指向Node结构体的指针
 */
void func2(Node* node) {
    node->use = func1;  // 将函数指针切换为func1，下次调用将执行func1
    printf("%d\n", ++(node->a));  // a自增1后打印（先增后打）
}

int main() {
    const char* s = "Your journey begins here!";  // 定义常量字符串，将存储到柔性数组中
    
    // 为Node结构体动态分配内存：
    // 总大小 = 结构体本身大小 + 字符串长度 + 1（字符串结束符'\0'）
    Node* P = (Node*)malloc(sizeof(Node) + (strlen(s) + 1) * sizeof(char));
    
    // 将字符串复制到柔性数组string中（柔性数组在结构体末尾，随结构体一起分配内存）
    strcpy(P->string, s);
    
    P->use = func1;  // 初始化函数指针，首次调用执行func1
    
    // 初始化a的值：结构体大小 * 50 + 共用体大小
    // 注：sizeof(Node)计算为4（int a）+20（union data）+8（函数指针）=32字节（64位系统）
    P->a = sizeof(Node) * 50 + sizeof(union data);  // 32*50 + 20 = 1620
    
    // 循环执行：当a < 2028时，通过函数指针调用func1或func2
    while (P->a < 2028) {
        P->use(P);  // 首次调用func1，之后交替调用func2、func1...
    }
    
    free(P);  // 释放动态分配的内存，避免内存泄漏
    return 0;
}
//运行结果如下
//Your journey begins here!
//2025
//Your journey begins here!
//2026
//Your journey begins here!
//2027
//Your journey begins here!
//2028