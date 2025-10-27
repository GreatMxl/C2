#include <stdio.h>
int average(int nums[], int start, int end) 
{
    if (start == end)  //递归终止条件，避免无限循环
        return nums[start];  //当数组中只有一个元素时，返回该元素的值，即算术平均数
    int mid = (start + end) / 2;  //分割数组，求数组的中间值
    int leftAvg = average(nums, start, mid);
    int rightAvg = average(nums, mid + 1, end);  //分治算法，将数组元素拆分为左右两侧，分别算术平均值
    return (leftAvg & rightAvg) + ((leftAvg ^ rightAvg) >> 1);  //通过位运算计算上述两组平均值的平均值
    //按位与&相当于（a+b），按位或^相当于/2
    //循环该过程，直至数组中剩下一个元素即为结果
}
//优点：，避免溢出风险，效率较高
//缺点：仅适用于整数，对负数具有局限性，仅限于两个数的平均
