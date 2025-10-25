#include <stdio.h>
#include <stdlib.h>

// 定义结果结构体
struct result 
{
    int *arr;  // 存储数组元素
    int length; // 数组长度
};

// 拼接两个数组
void your_concat(int arr1[], int len1, int arr2[], int len2, struct result *result) 
{
    result->length = len1 + len2;
    result->arr = malloc(result->length * sizeof(int));
    // 复制第一个数组
    for (int i = 0; i < len1; i++)
        result->arr[i] = arr1[i];
    // 复制第二个数组
    for (int i = 0; i < len2; i++)
        result->arr[len1 + i] = arr2[i];
}

// 简单选择排序
void your_sort(struct result result) 
{
    for (int i = 0; i < result.length; i++) 
    {
        int min = i;
        // 找到最小元素位置
        for (int j = i + 1; j < result.length; j++)
            if (result.arr[j] < result.arr[min])
                min = j;
        // 交换
        int temp = result.arr[i];
        result.arr[i] = result.arr[min];
        result.arr[min] = temp;
    }
}

// 去重（基于已排序数组）
void your_dedup(struct result *result) 
{
    if (result->length <= 1) return;
    
    int count = 1;
    // 统计不重复元素数量
    for (int i = 1; i < result->length; i++)
        if (result->arr[i] != result->arr[i-1])
            count++;
    
    // 保存不重复元素
    int *new_arr = malloc(count * sizeof(int));
    new_arr[0] = result->arr[0];
    for (int i = 1, j = 1; i < result->length; i++)
        if (result->arr[i] != result->arr[i-1])
            new_arr[j++] = result->arr[i];
    
    // 更新结果
    free(result->arr);
    result->arr = new_arr;
    result->length = count;
}

// 打印函数（题目隐含需要）
void print_result(struct result res) 
{
    printf("Length: %d, Elements: ", res.length);
    for (int i = 0; i < res.length; i++)
        printf("%d ", res.arr[i]);
    printf("\n");
}

// 主函数（题目提供）
int main() {
    int arr1[] = { 6, 1, 2, 1, 9, 1, 3, 2, 6, 2 };
    int arr2[] = { 4, 2, 2, 1, 6, 2 };
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    struct result result;
    your_concat(arr1, len1, arr2, len2, &result);
    print_result(result);
    your_sort(result);
    print_result(result);
    your_dedup(&result);
    print_result(result);
    free(result.arr);
    return 0;
}
//运行结果如下
//Length: 16, Elements: 6 1 2 1 9 1 3 2 6 2 4 2 2 1 6 2 
//Length: 16, Elements: 1 1 1 1 2 2 2 2 2 2 3 4 6 6 6 9 
//ength: 6, Elements: 1 2 3 4 6 9 