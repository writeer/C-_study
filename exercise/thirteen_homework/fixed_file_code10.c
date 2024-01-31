#include <stdio.h>
#include <stdlib.h>
#define SLEN 30
int main(void){
    FILE *fp;
    char ch[SLEN];
    long num;
    int prt;//储存要打印的字符
    puts("Enter a filename:");
    if (scanf("%s",ch) != 1)
    {
        fprintf(stderr,"Input error.\n");
    }
    if ((fp = fopen(ch,"r")) == NULL)
    {
        fprintf(stderr,"Can't open %s file.\n",ch);
        exit(EXIT_FAILURE);
    }
    puts("Enter the file location you want:");
    while (scanf("%ld",&num) == 1)
    {
        fseek(fp,num,SEEK_SET);
        while ((prt = getc(fp)) != EOF)
            putchar(prt);
        puts("Enter a next file location(-1 or q to quit):");
    }
    fclose(fp);
    return 0;
}