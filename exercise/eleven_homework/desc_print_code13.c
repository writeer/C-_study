/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这题可以写的应对多种情况，但是我比较懒，今天没什么精神，就粗制滥造一下了。
//我又犯病了，原本只要重新排序数组然后显示就可以了，我现在一直想不改变原数组，只操作显示，又搞麻烦了。
//如果在弄一个数组来保存，那样太浪费内存了，我也不想这样做。
//算了，我摆烂了，我要乱改原来的数组了.
//艹，实在想不到好办法了，就用最简单粗暴的了

int main(){
    char ch[80];
    char *ptr[10];
    //char * ptr;
    int i,j,m = 1;
    //char chr[10][10];
    puts("Enter a character string:");
    fgets(ch,80,stdin);
    for (i = strlen(ch) - 1,j = 0; i > 0; i--)
    {
        
        //printf("%c",ch[i]);
        if (ch[i] == ' ')
        {
            m++;
            ch[i] = '\0';
            ptr[j] = ch + i + 1; 
            j++;
           // for (int n = 0; n < j; n++)
           // {
           //     putchar(*ptr);
           // } 
        }
        //printf("%p\n",ptr[j]);
    }
    ptr[j + 1] = ch;
    for (int n = 0; n < m; n++)
    {
        printf("%s 111\n",ch);
        printf("%s \n",ptr[n]);
        for (int c = 0; c < strlen(ptr[n]); c++)
        {
            printf("%c",*ptr[n]++);
        }
        printf(" ");
    }
    
    system("pause");
    return 0;
}*/
//懒得写了，直接用这个办法，用二维数组把字符分割存储，然后倒序打印。
//越调越心烦，就用这个从网上看来的了。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char str[20]="see you later";
    char str2[10][10]={0};
    int col=0;
    int row=0;
   // puts("Enter a character string:");
    //fgets(str,20,stdin);
    for(int i=0;i<20;i++)
    {
        if (str[i] == '\0')
            str[i] = ' ';
        
        if(str[i]==' ')
        {
            col++;
            row=0;
        }
        else 
        {
            str2[col][row]=str[i];
            row++;
            str2[col][row]=' ';
        }    
    }
    for(int i=col;i>=0;i--)
    {
        printf("%s",str2[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}