#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BYTES_PER_LINE 16
/**

@brief 程序入口函数

@param argc 命令行参数个数

@param argv 命令行参数列表

@return 返回程序运行状态，0 表示正常退出
*/
int main(int argc, char *argv[]) {
    FILE *fp;/*< 文件指针 */
    unsigned char buffer[BYTES_PER_LINE];/*< 缓冲区，用于存储读取的字节 */
    int bytes_read, line_offset = 0;/**< 当前行偏移量和读取的字节数 */
    /* 打开文件 */
    if (argc == 1) {
        fp = stdin;/*< 如果未传入参数，则从标准输入中读取 */
    } else if (argc == 2) {
        fp = fopen(argv[1], "rb"); /*< 打开指定文件 */
        if (!fp) {
            perror("Error opening file");
            exit(1);
        }
    } else {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(1);
    }
    /* 逐行读取并打印 */
    while ((bytes_read = fread(buffer, sizeof(unsigned char), BYTES_PER_LINE, fp)) > 0) {
        int i;/**< 循环计数器 */
        printf("%06X", line_offset);
        /* 打印每个字节的十六进制表示形式 */
        for (i = 0; i < BYTES_PER_LINE; i++) {
            if (i % 4 == 0) printf(" "); /**< 每 4 个字节之间用空格分隔 */
            if (i < bytes_read) {
                printf("%02X", buffer[i]);/**< 打印字节的十六进制表示形式 */
            } else {
                printf("  "); /**< 如果读取的字节数小于 BYTES_PER_LINE，用空格填充 */
            }
        }

        printf(" *");
        /* 打印每个字节对应的 ASCII 字符或点号 */
        for (i = 0; i < bytes_read; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);/**< 如果是可打印字符，则打印该字符 */
            } else {
                printf(".");/**< 如果不是可打印字符，则打印点号 */
            }
        }
        printf("*\n");

        line_offset += BYTES_PER_LINE;/**< 更新偏移量 */
    }

    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}
