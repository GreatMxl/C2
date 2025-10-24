#include <stdio.h>
int main()
{
    char p1[]={'W','e','l','c','o','m','e','\0'};
    char p2[]="join us\0",p4[]="Xiyou_Linux_Group";
    const char* p3 ="Xiyou Linux Group\0\n2025\0";
    if(strcmp(p1,p2))  //比较两字符串的字典序，W>J,当 p1 和 p2 不相等时，strcmp 返回非 0，条件为真，执行 printf
    {
        printf("%s to %s !\n",p1,p2);
    }
    if (strlen(p3)>sizeof(p3))  //strlen 函数用于计算字符串的有效长度（不包含终止符 \0）,17>8，故执行 printf
    {
        printf("%s\n",p3);
    }
    if (sizeof(p1)==sizeof(p2))  //sizeof 运算符用于计算变量（包含终止符 \0） / 类型占用的内存字节数,8!=9，故不执行 printf
    {
        printf("%s\n",p4);
    }
    printf("%zu\n" "%zu\n",strlen(p3),sizeof(p3));
    printf("%zu\n" "%zu\n",sizeof(p1),sizeof(p2));
    return 0;
}
//输出结果如下
//Welcome to join us !
//Xiyou Linux Group
//17
//8
//8
//9
