#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * string_in(const char * scr,const char * dest);
//后面想了好久，最后完美主义作祟，我决定单独写一个处理换行的函数，这样就能解决所有问题了。
void Line_feed(char * row);

int main(void){
    char s1[40];
    char s2[40];
    char * cr;
    char acter;
    while (acter != EOF)
    {
    puts("输入一个字符串：");
    fgets(s1,40,stdin);
    //char s1[] = "Heloow s";
    puts("输入查找字符.");
    fgets(s2,40,stdin);
    Line_feed(s2);
    cr = string_in(s1,s2);
    //printf("%p  %p\n",s1,cr);
    if(cr)
        fputs(cr,stdout);
    else
        puts("未查找到相关字符");
    puts("按回车继续，输入ctrl-z结束。");
    fflush(stdin);
    acter = getchar();
    }
    system("pause");
    return 0;
}
//这个函数还是比较难的，一开始想了好久，突然发现就是过一遍字符串就行了，不用迭代，前面不符合后面自然也不会符合。
char * string_in(const char * scr,const char * dest){
    int i = 0,j;
   
        for ( j = 0; j < strlen(scr); j++)
        {
            if(dest[i] != '\0'){//原来是\n因为最后结尾前保存过一个换行符，如果是单纯的字符串就换成\0，或者用专门的函数喊处理换行。
            //if(dest[i] == '\n') {,continue;}//以为我每次输入都会多一个换行，所以专门处理一下换行符，这样正常字符也没问题。
            //每次都会多一个换行的原因在于fgets会保存换行，用gets可以解决这个问题，但是gets不安全，或者用get_s也行
            if (dest[i] == scr[j])
                i++;
            else
                i = 0;
            }
            else
                break;
            //printf("%c",dest[i]);
        }
    //if(j == strlen(scr))
    //    i++;
    //printf("j = %d,i = %d\n",j,i);
    //if(i == 0)
    //if( i == strlen(dest))
    //if( i < strlen(dest))
    if(i == 0)
        return NULL;
    return (scr + j - i);
}

void Line_feed(char * row){
    for (int i = 0; i < strlen(row); i++)
    {
        if (row[i] == '\n')
        {
            row[i] = '\0';
        }
    }
    
}