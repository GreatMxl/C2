#include <stdio.h>
int main(void) 
{
    char arr[] = {'L', 'i', 'n', 'u', 'x', '\0', '!'}, str[20];
    short num = 520;
    int num2 = 1314;
    printf("%zu\t%zu\t%zu\n", sizeof(*&arr), sizeof(arr + 0),  //*&arr仍为arr，7个字节；
    //arr与整数0相加时，数组名隐式转换为指向首元素的指针（类型为char*），指针大小在64位系统中为8字节
           sizeof(num = num2 + 4));  //sizeof仅关注表达式结果的类型，赋值不影响结果，short类型是2字节
    printf("%d\n", sprintf(str, "0x%x", num) == num);  
    //将num=520以十六进制格式"0x%x"写入str。520的十六进制为208，故str内容为"0x208"，长度为 5
    printf("%zu\t%zu\n", strlen(&str[0] + 1), strlen(arr + 0));
    //&str[0]+1指向str的第二个字符，从'x'开始的字符串为"x208"，长度为 4；arr + 0指向arr首元素，长度为5
}
//运行结果如下
//7       8       2                                                                                                           
//0                                                                                                                           
//4       5