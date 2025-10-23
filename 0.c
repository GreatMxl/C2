#include <stdio.h>
int main() 
{
    int b;
    // 输入b（确保b≥0）
    printf("请输入b,b≥0: ");
    scanf("%d",&b);
    if (b == 0)
    {
        printf("不需要捡任何石头 乘积为1 即a^0\n");// 特殊情况：b=0时，乘积为a^0=1，不需要捡任何石头
        return 0;
    }
    printf("需要捡的石头编号为：");
    int stone_num = 1;  // 当前检查的石头编号（从1开始）
    int temp = b;       // 临时变量存储b，用于计算
    while (temp > 0)
    {
       if (temp % 2 == 1) 
       {
            printf("%d ", stone_num); // 检查temp的二进制最低位是否为1（若是，则需要捡当前石头）
       }
       temp = temp / 2;    // 处理下一位（相当于二进制右移一位）
       stone_num++;      // 石头编号递增（下一块石头）
    }

    printf("\n这些石头的重量乘积为a的%d次方\n", b);
    return 0;
}
//另有如下方案
//将10进制数转化为2进制数，存入arr数组，但为该2进制数的倒序排列
//将该数组元素倒置排列
//若存在莫一位置上元素为1,则输出该位置元素编号+1c
//输出的数即为所需的编号

