//打印文件中包含特定字符的行
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 256
void strcpy_line(FILE *,int n);

int main(int argc, char const *argv[])
{//接收两个参数第一个是字符，第二个是文件名
    FILE *fp;
    if(argc == 3){
        if((fp = fopen(argv[2],"r")) == NULL){
            printf("Can't open %s\n",argv[2]);
            exit(EXIT_FAILURE);
        }
        strcpy_line(fp,argv[1][0]);
    }
    else{
        fprintf(stderr,"input error\n");
        exit(EXIT_FAILURE);
        }
    fclose(fp);
    return 0;
}

void strcpy_line(FILE * fp,int n){
    char line[BUF];
    while (fgets(line,BUF,fp) != NULL)
    {
        if(strchr(line,n) != NULL)
            fputs(line,stdout);
    }
    
}