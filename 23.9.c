#include <stdio.h>
int main(int argc, char* argv[]) 
{
    printf("[%d]\n", argc);
    while (argc) 
    {
      ++argc;  //循环条件是 argc != 0 时执行 ++argc,
    }
    int i = -1, j = argc, k = 1;
    i++ && j++ || k++;  //-1&&0，结果为0，视为假,使用后自增,行右侧 k++,使用后自增
    printf("i = %d, j = %d, k = %d\n", i, j, k);
    return 0;
}
//最终打印
//i = 0, j = 1, k = 2
