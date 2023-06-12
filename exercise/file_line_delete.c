#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/**
 * @brief 这个代码有两个问题，一个是覆写源文件，会导致自动操作，源文件的数据不会完全覆写
 * 因为我删除了行号，所以会导致源文件的内容保持，导致混乱。
 * 第二是，不能用指针备份，因为只是两个文件指针的别名。
 * 
 */



/**
 * @brief 删除所有行号
 * 
 * @param fp 
 * @return int 成功返回1，失败返回0
 */
int delete_line(FILE *fp);

/**
 * @brief 这个代码用于删除复制文件中的行号，因为我懒得手删，顺便练习
 * 
 * 
 * @return int 
 */
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        FILE *fp = fopen(argv[1], "r+");
        if (fp == NULL)
        {
            fprintf(stdout, "文件打开失败或文件名不正确");
            return 1;
        }
        delete_line(fp);
    }
    else
    {
        char str[50];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // 去除输入中的换行符
        FILE *fp = fopen(str, "r+");
        if (fp == NULL)
        {
            fprintf(stdout, "文件不存在，请输入正确的文件路径！");
            return 1;
        }
        delete_line(fp);
    }
    remove(argv[1]);
    rename("temp.txt",argv[1]);
    printf("删除结束");
    return 0;
}

int delete_line(FILE *fp)
{
    rewind(fp);
    FILE *temp =  fopen("temp.txt","w+");
    char str[256]; // 假设一行不超过256个字符
    long backup;
    int i = 0;
    while (fgets(str, sizeof(str), fp))
    {
        //backup = ftell(fp); // 读取后偏移指针

        if (strlen(str) != 0)
        {
            while (isdigit(str[0]) || isdigit(str[1]))
            {
                strcpy(str, str + 1); // 移动字符串
            }
            int flag = fprintf(temp, "%s", str); // 写入设置好的字符串
            if (flag < 0)
            {
                fprintf(stderr, "写入失败");
                fclose(fp);
                return 0;
            }
        }
    }
    fclose(temp);
    fclose(fp);
    return 1;
}
