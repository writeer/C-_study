/**
 * @file fgrep.c
 * @author your name (you@domain.com)
 * @brief 实现unix里的 fgrap命令，第一个参数是字符串参数
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief 
 * 
 *
 * 
 * @param src 源字符串
 * @param dst 要对比的字符串
 * @return int 如果匹配则返回1，否则返回0
 */
int cmp_str(char * src,char * dst);

/**
 * @brief 打印文件中匹配的字符串的行号
 * 
 * @param str 要查找的字符串
 * @param filename 文件名
 */
void print_str(char * str,char * filename);

/**
 * @brief 主函数，接受命令行参数并调用其他函数
 * 
 * @param argc 命令行参数数量
 * @param argv 命令行参数列表
 * @return int 返回程序执行状态
 */
int main(int argc,char *argv[])
{
    FILE *fp;
    //如果没有文件名参数
    if (argc == 2){
        printf("输入文件名：");
        char *buffer = (char *) malloc(510 * sizeof(char));
        fgets(buffer,510,stdin);
        buffer = (char *)realloc(buffer,strlen(buffer) + 1);//让字符串变为合适的大小
        int end = strlen(buffer);
        for (int i = 0; i < end; i++)//分割字符串
        {
            if(isspace(buffer[i]))
            {
                buffer[i] = '\0';
            }
        }
        int i = 0;
        while(i <= end)
        {
            print_str(argv[1],&buffer[i]);
            i += strlen(&buffer[i]) + 1;
            while (buffer[i] == '\0')
            {
                i++;
            }
        }
        free(buffer);
        
    }
    else if (argc > 2){
        for (int i = 2; i < argc; i++)
        {
            print_str(argv[1],argv[i]);
        }
            
    }
    else{
        fprintf(stderr,"参数错误！");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void print_str(char * str,char * filename)
{
    char Butters[510];//假设一行不超过510个字符
    int line = 0;
    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        fprintf(stderr,"文件打开错误");
        exit(EXIT_FAILURE);
    }
    while(fgets(Butters,256,fp) != NULL){
        line++;
        //因为下面这个的条件不会完整匹配单词，所以单独写了个函数
        /*if(strstr(Butters,str) != NULL)
        {
            printf("%s : %d line \n",filename,line);
        }*/
        if(cmp_str(Butters,str))
        {
            printf("%s : %d line \n",filename,line);
        }
        }
    fclose(fp);
}

int cmp_str(char * src,char * dst)
{
    char *token;
    token = strtok(src," ");
    while (token != NULL)
    {
        if(strcmp(token,dst) == 0)
            return 1;
        token = strtok(NULL," ");
    }
    return 0;
}