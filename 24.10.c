#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义结果结构体，用于存储去重排序后的数组及其长度
typedef struct {
    int* arr;
    int len;
} result;

// 函数声明
void your_sort(int* arr1, int len1, int* arr2, int len2, result* res);

int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 10};
    int arr2[] = {2, 1, 4, 3, 9, 6, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    result result;
    your_sort(arr1, len1, arr2, len2, &result);
    for (int i = 0; i < result.len; i++) {
        printf("%d ", result.arr[i]);
    }
    free(result.arr); // 释放动态分配的内存
    return 0;
}

void your_sort(int* arr1, int len1, int* arr2, int len2, result* res) {
    int total_len = len1 + len2;
    // 动态分配内存存储合并后的数组
    int* merged = (int*)malloc(total_len * sizeof(int));
    if (merged == NULL) {
        res->arr = NULL;
        res->len = 0;
        return;
    }

    // 合并两个数组
    memcpy(merged, arr1, len1 * sizeof(int));
    memcpy(merged + len1, arr2, len2 * sizeof(int));

    // 对合并后的数组进行升序排序
    for (int i = 0; i < total_len - 1; i++) {
        for (int j = 0; j < total_len - 1 - i; j++) {
            if (merged[j] > merged[j + 1]) {
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    // 统计去重后的元素个数
    int unique_len = 0;
    int* unique_temp = (int*)malloc(total_len * sizeof(int)); // 临时存储唯一元素
    if (unique_temp == NULL) {
        free(merged);
        res->arr = NULL;
        res->len = 0;
        return;
    }

    if (total_len > 0) {
        unique_temp[unique_len++] = merged[0]; // 第一个元素一定是唯一的
        for (int i = 1; i < total_len; i++) {
            if (merged[i] != merged[i - 1]) { // 只保留与前一个元素不同的元素
                unique_temp[unique_len++] = merged[i];
            }
        }
    }

    // 为结果分配内存并复制唯一元素
    res->arr = (int*)malloc(unique_len * sizeof(int));
    if (res->arr != NULL) {
        memcpy(res->arr, unique_temp, unique_len * sizeof(int));
    } else {
        unique_len = 0; // 内存分配失败时长度为0
    }
    res->len = unique_len;

    // 释放临时分配的内存
    free(merged);
    free(unique_temp);
}