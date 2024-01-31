/**
 * @file part_cost.c
 * @author your name (you@domain.com)
 * @brief C和指针第十五章第十一题 这题可以用数据结构，链表或者树的APT来做，储存数据，读取数据，操作数据
 * 但是那样的话，我只是在复习，为了学到新东西，我决定用文本的方式进行数据存储和读取。
 * @version 0.1
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "part_cost.h"

void menu();

int main(int argc,char **argv)
{
    if (argc > 1)//判断是否有文件
    {//打印菜单，这个内容可以用用个函数包装，每次打印，但是我有点低烧就不写了

        FILE *fp = fopen(argv[1],"r+");//查看是否有这个文件
        if(fp == NULL)
        {
            fp = fopen(argv[1],"w+");//如果没有则创建文件
            if(fp == NULL)
            {
                fprintf(stderr,"文件创建失败！");
                exit(EXIT_FAILURE);
            }
            
        }
        cost * costs = file_read(fp);
        char buffer[256] = {0},*str; // 用以储存临时数据
        while (1)
        {
            menu();
            printf("> ");
            fgets(buffer,256,stdin);
            str = strtok(buffer," ");
            if (strcmp(str,"new") == 0)//判断内容
            {
                if(!news(costs))
                    fprintf(stderr,"参数错误！");
            }
            else if (strcmp(str,"buy") == 0)
            {
                if(!buy(costs))
                    fprintf(stderr,"参数错误！");
            }
            else if (strcmp(str,"shell") == 0)
            {
                if(!shell(costs))
                    fprintf(stderr,"参数错误！");
            }
            else if (strcmp(str,"print") == 0)
            {
                print_num(costs);
            }
            else if (strcmp(str,"delete") == 0)
            {
                if(!deletes(costs))
                    fprintf(stderr,"参数错误！");
            }
            else if (strcmp(str,"total\n") == 0)
            {
                total(costs);
            }
            else if (strcmp(str,"end\n") == 0)
            {
                file_write(fp,costs);
                break;
            }
            else
            {
                fprintf(stderr,"命令错误！(不存在的命令)");
            }

        }
    }
    else
    {
        fprintf(stderr,"参数错误");
        exit(EXIT_SUCCESS);
    }
    
    exit(EXIT_SUCCESS);
}

void menu()
{
    puts("\n参数之间用',' 分隔");
    puts("可用命令 new 零件简述，零件数量，零件单价");
    puts("可用命令 buy 零件号，零件数量，零件单价 ,买");
    puts("可用命令 shell 零件号，零件数量，出售价格，卖");
    puts("可用命令 print 零件号 or all 打印指定零件信息或者一表格形式打印全部信息");
    puts("可用命令 delete 零件号 ,删除指定零件");
    puts("可用命令 total 打印和计算文件中所有零件的总价值");
    puts("end 退出");
}