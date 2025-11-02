#include <stdlib.h>  // 为了使用malloc和free函数

typedef int (*Predicate)(int);//函数定义，接受int，返回int

int *filter(int *array, int length, Predicate predicate, int *resultLength) 
//int *array：原数组（待筛选的数组）
//int length：原数组的长度
//Predicate predicate：条件函数（回调函数），用于判断元素是否符合条件
//int *resultLength：输出参数，用于返回筛选后数组的长度
{
    // 计算满足条件的元素个数
    *resultLength = 0;
    for (int i = 0; i < length; i++) //遍历原数组，通过 predicate 函数判断每个元素是否符合条件，统计符合条件的元素总数，存入 *resultLength
	{
        if (predicate(array[i])) 
		{
            (*resultLength)++;
        }
    }

    // 为结果数组分配内存
    int *result = (int *)malloc(*resultLength * sizeof(int));//根据统计的长度，用 malloc 动态分配内存，存储筛选后的元素
    if (result == NULL) //若内存分配失败，返回 NULL并重置结果长度
	{
        *resultLength = 0;  // 分配失败时结果长度为0
        return NULL;
    }

    // 将满足条件的元素存入结果数组
    int index = 0;
    for (int i = 0; i < length; i++) //再次遍历原数组
	{
        if (predicate(array[i])) 
		{
            result[index++] = array[i];//将符合条件的元素依次存入新分配的内存中
        }
    }

    return result;//最终返回结果数组
}

// 以下是原有的函数和主函数（无需修改）
int isPositive(int num) 
{ return num > 0; }//判断一个数是否为正数（num > 0 时返回非 0，否则返回 0）

int main(void)
{
    int array[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);//计算数组长度即元素个数
    int resultLength;
    int *filteredNumbers = filter(array, length, isPositive, &resultLength);//调用 filter 函数进行数组筛选，
    for (int i = 0; i < resultLength; i++) {
        printf("%d ", filteredNumbers[i]);并将返回的结果数组地址赋值给指针 filteredNumbers
    }
    printf("\n");
    free(filteredNumbers);  // 释放动态分配的内存，因filter在调用中使用malloc分配内存，不会自动释放
    return 0;
}