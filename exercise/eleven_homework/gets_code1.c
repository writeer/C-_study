//获取n个字符，包括换行空格等
#include <stdio.h>
#include <string.h>

void gets_ss(char * ptr,int n);

int main(void){
    int n = 8;
    char row[40];
    gets_ss(row,n);
    fputs(row,stdout);
    fflush(stdin);
    getchar();
    return 0;
}

void gets_ss(char * ptr,int n){
    
    fgets(ptr,n,stdin);
    return;
}