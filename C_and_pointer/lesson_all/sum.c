/**
 * @file sum.c
 * @author your name (you@domain.com)
 * @brief C和指针第十五章第十题，检验效验和(cheeksum)
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief 接收一个文件，并返回效验和
 * 
 * @param fp 
 * @return int 
 */
int Cheek_Sum(char * file);

int main(int argc,char **argv)
{
    int sum;
    if (argc > 1)//输入文件名，或存在参数
    {
        if(strcmp(argv[1],"-f") == 0)//判断是否-f参数
        {
            for (int i = 2; i < argc; i++)
            {
                sum = Cheek_Sum(argv[i]);
                char * filename = (char *)malloc(strlen(argv[i]) + 5);
                strcpy(filename,argv[i]);//生成创建文件名
                strcat(filename,".cks");
                FILE *fp = fopen(filename,"w");
                if(fp == NULL){
                    fprintf(stderr,"文件输出失败！");
                    exit(EXIT_FAILURE);
                }
                fprintf(fp,"%d",sum);
                printf("File %s now contains %d\n",filename,sum);
                free(filename);
                fclose(fp);
            }
            
        }
        else
        {
             for (int i = 1; i < argc; i++)
            {
                sum = Cheek_Sum(argv[i]);
                fprintf(stdout,"%d\n",sum);
            }
        }
    }
    else if (argc == 1)//不存在文件名
    {
        char file[30] = {0};
        while (1)
        {
            printf("输入文件名(输入ctrl -D 退出):");
            scanf("%s",file);
            sum = Cheek_Sum(file);
            printf("%d\n",sum);
        }
        
    }
    else
    {
        fprintf(stderr,"-f   输出文件名");
        fprintf(stderr,"sum ");
        exit(EXIT_FAILURE);
    }
    
}

int Cheek_Sum(char *file)
{
    FILE *fp = fopen(file,"r");
    if(fp == NULL){
        fprintf(stderr,"文件打开失败！");
         exit(EXIT_FAILURE);
    }
    char ch;
    int sum = 0;
    while((ch = fgetc(fp)) != EOF)//计算效验和
    {
        sum += ch;
    }
    fclose(fp);
    return sum;
}