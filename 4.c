#include <stdio.h>
void findUndercoverIDs(int nums[], int size) 
{
    int xorAll = 0,id_a = 0,id_b = 0;
    for (int i = 0; i < size; i++) 
    {
        xorAll ^= nums[i];   //计算所有元素的异或结果 xorAll，找到x^y
    }
    int diffBit = xorAll & -xorAll;   //找到区分 x和y 的二进制位
                                      //-xorAll 是 xorAll 的补码，与原码按位与后，仅保留最低位的1，其余位为0
    for (int i = 0; i < size; i++)    
        if(nums[i] & diffBit)     //按位与运算，判断某一二进制位是否为1
        {
            id_a ^= nums[i];      
        } 
        else                   //分组异或，分离 x 和 y
        {
            id_b ^= nums[i];
        }
    
    printf("These nums are %d %d\n", id_a, id_b);
}
//若数组中只有两个元素 x和y 出现一次，其余元素均出现两次
//则数组所有元素异或的结果等价于 x ^ y（因为成对元素异或后为 0，最终剩下 x ^ y）
//找到 x ^ y 中任意一个为 1 的二进制位（表示 x 和 y 在该位上不同），以此为依据将数组分为两组，两组分别包含 x和y
//每组内所有元素异或，最终得到的两个结果就是 x和y