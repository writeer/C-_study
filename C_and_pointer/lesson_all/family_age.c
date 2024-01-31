/**
 * @file family_age.c
 * @author your name (you@domain.com)
 * @brief 读取一个文件，计算每个家族的平均年龄，假设每行十个家族
 * @version 0.1
 * @date 2023-03-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char butter[1024] ={0};
    char number[1024] = {0};//这里可以用动态数组
    int sum = 0,count = 0;
    FILE * fp = fopen("family.txt","r");
    if (fp == NULL)
        return 0;
    while (fgets(butter,40,fp) != NULL)//查看有几行
    {
        strcat(number,butter);
        count++;
    }
    int j = 0,ch;
    for (int i = 0; i < count; i++)
    {
        for (sum = 0,ch = 0;number[j] != '\n' && number[j] != '\0'; j++)
        {
            sum += atoi(number + j);//记录指针偏移，方便转换整数
            ch++;//记录整数个数
            while(number[j] != ' ' && number[j] != '\0')//跳过整数后面的字符
            {
                j++;
                if (number[j] == '\n')
                {
                    j--;//移动到换行，方便离开循环
                    break;
                }
                
            }
        }
        j++;//移动到换行后面的下一个数字
        printf("this family avg age: %5.2f \n",(float)sum / ch);
    }
    
    system("pause");
    fclose(fp);
    return 0;
    
}