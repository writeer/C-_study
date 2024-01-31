#include <stdio.h>
#include <string.h>

#define SIZE 40
//处理空格
char space_handle(char *);

int main(void){
    char row[SIZE];
    char bol = ' ';//判断字符
    while (bol != '\n')
    {
        puts("Enter a character string(Click Enter to quit):");
        fgets(row,SIZE,stdin);
        bol = space_handle(row);
        fputs(row,stdout);
    }
    return 0;
}

char space_handle(char * ptr){
    int i;
    for ( i = 0; i < strlen(ptr); i++)
    {
        if (ptr[i] == 32)
            for (int j = i;j < strlen(ptr); j++)
            {
                ptr[j] = ptr[j+1];
            }
    }
    return *ptr;
}