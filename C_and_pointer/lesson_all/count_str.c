/**
 * @file count_str.c
 * @author your name (you@domain.com)
 * @brief 读取标准输入中的字符，然后计算各类字符所占百分比,不能用if语句
 * @version 0.1
 * @date 2023-03-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <ctype.h>

int main()
{
    int count[7] = {0};//0:控制字符 1:空白字符 2:数字 3:小写字母 4:大写字母 5:标号符号 6:不可打印字符
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        count[0] += iscntrl(ch) ? 1 : 0;
        count[1] += isspace(ch) ? 1 : 0;
        count[2] += isdigit(ch) ? 1 : 0;
        count[3] += islower(ch) ? 1 : 0;
        count[4] += isupper(ch) ? 1 : 0;
        count[5] += ispunct(ch) ? 1 : 0;
        count[6] += isprint(ch) ? 1 : 0;
    }
    float sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum += count[i];
    }
    printf("总计: %g\n",sum);
    printf("ctrl: %.2f%% \n",count[0] / sum * 100);
    printf("space: %.2f%% \n",count[1] / sum * 100);
    printf("number: %.2f%% \n",count[2] / sum * 100);
    printf("lower case: %.2f%% \n",count[3] / sum * 100);
    printf("upper case: %.2f%% \n",count[4] / sum * 100);
    printf("Label symbol: %.2f%% \n",count[5] / sum * 100);
    printf("printable: %.2f%% \n",count[6] / sum * 100);
    fflush(stdin);
    getchar();
    return 0;
}