#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 60

void scr_char(char [][SIZE]);//打印源字符
void ascll_print(char * []);//按照ascll的顺序打印
void length_print(char * []);//按照长度递增打印
void first_print(char * []);//按照第一个单词的长度打印
//因为这题有点折磨我，我一直想用更好的方法，或者说算法，但是我实在想不到，所以就全部用选择排序和指针数组了
int main(void){
    char acter[10][SIZE];
    char * ter[10];
    int n = 0;
    int bol = 0;
    puts("Enter ten strings:");
    while (fgets(acter[n],60,stdin) && n < 9)
        n++;
    n = 0;
    while (n < 10)
    {
        ter[n] = acter[n];
        n++;
    }
    
    while (bol != 5)
    {
        puts("***************************************************");
        puts(" 请选择以下选项");
        puts("  1,打印源字符串     2,按照ascll码打印");
        puts("  3,按照长度打印     4,按照第一个单词的长度打印");
        puts("  5,退出");
        puts("***************************************************");
        printf(":");
        scanf("%d",&bol);
        while(bol < 1 || bol > 5){
            printf("\n请输入正确的选项:");
            scanf("%d",&bol);
        }
        switch (bol)
        {
        case 1:
            scr_char(acter);
            break;
        case 2:
            ascll_print(ter);
            break;
        case 3:
            length_print(ter);
            break;
         case 4:
            first_print(ter);
            break;
        default:
            break;
        }
    }
    puts("Done!");
    return 0;
}

void scr_char(char arg[][SIZE]){
    for (int i = 0; i < 10; i++)
    {
        fputs(*(arg + i),stdout);
    }
    return;
}

void ascll_print(char *arg[]){
    char * ptr[10];
    char * temp;
    int i,j;
    for (int k = 0; k < 10; k++)
        ptr[k] = arg[k];
    
    for ( i = 0; i < 10; i++)
    {
        for ( j = i+1; j < 10; j++)
        {
            if(strcmp(ptr[i],ptr[j]) > 0){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    for (int n = 0; n < 10; n++)
    {
        printf("%s",ptr[n]);
    }
    
    return;
}

void length_print(char * arg[]){
    char * ptr[10];
    char * temp;
    int i,j;
    for (int k = 0; k < 10; k++)
        ptr[k] = arg[k];
    
    for ( i = 0; i < 10; i++)
    {
        for ( j = i+1; j < 10; j++)
        {
            if(strlen(ptr[i]) > strlen(ptr[j])){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    for (int n = 0; n < 10; n++)
    {
        printf("%s",ptr[n]);
    }
    
    return;
}

void first_print(char * arg[]){
    char * ptr[10];
    char * temp;
    int i,j;
    int m,c;//统计第一个单词长度
    for (int k = 0; k < 10; k++)
        ptr[k] = arg[k];
    
    for ( i = 0; i < 10; i++)
    {
        for ( j = i+1; j < 10; j++)
        {//使用isspace可以增加识别换行和制表符，这样使得这个函数更加智能
            for (m = 0;isspace(ptr[i][m]) == 0; m++)
                ;
            for (c = 0;isspace(ptr[j][c]) == 0; c++)
                ;
            
            if(m > c){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    for (int n = 0; n < 10; n++)
    {
        printf("%s",ptr[n]);
    }
    return;
}