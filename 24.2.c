int main() 
{
    char p0[] = "I love Linux";  //字符数组，编译器在最后自动加\0
    const char *p1 = "I love Linux\0Group";  //strcmp遇到\0停止，实则与p0表示相同
    char p2[] = "I love Linux\0";  //与p0相同
    printf("%d\n%d\n", strcmp(p0, p1), strcmp(p0, p2));  //p0=p1=p2,均返回0
    printf("%d\n%d\n", sizeof(p0) == sizeof(p1), strlen(p0) == strlen(p1));
    //p0是数组，字节数为12+1=13,strlen是12；p1是指针，64位系统字节数为8,strlen也为12c
    return 0;
}
//运行结果如下
//0
//0
//0
//1