#include <stdio.h>

int main() {
    FILE *fp = fopen("file1.txt", "r+"); // 打开文件流 fp

    if(fp == NULL)
    {
        return 0;
    }
    // 在文件1中读取数据
    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    printf("file1 content: %s\n", buf);

    // 将文件流关联到文件2上
    fp = freopen("file2.txt", "r", fp);

    // 在文件2中读取数据
    fgets(buf, sizeof(buf), fp);
    printf("file2 content: %s\n", buf);
    // 关闭文件流
    fclose(fp);
    getchar();
    return 0;
}
