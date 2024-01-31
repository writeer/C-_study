#include <stdio.h>
#include <stdlib.h>

int str_chr_conut(FILE *fp,char ch);

int main(int argc, char const *argv[])
{
    FILE *fp;
    char name[20] = {0};
    int count,i = 2;
    if (argc > 2)
    {
        while ( i < argc)
        {
            if((fp = fopen(argv[i],"r")) == NULL){
                fprintf(stderr,"Can't open %s file.\n",argv[i]);
                exit(EXIT_FAILURE);
            }
            count = str_chr_conut(fp,argv[1][0]);
            printf("%s is count %s : %d\n",argv[1],argv[i],count);
            i++;
        }
    }
    else if (argc == 2){
        while (name[0] != '\n')
        {
            puts("Enter your filename:");
            fscanf(stdin,"%19s",name);
             if((fp = fopen(name,"r")) == NULL){
                fprintf(stderr,"Can't open %s file.\n",argv[i]);
                exit(EXIT_FAILURE);
            }
            count = str_chr_conut(fp,argv[1][0]);
            printf("%s is count %s : %d\n",argv[1],name,count);
            puts("输入一个不存在的文件以退出.");
        }
    }
    else
        printf("Input error!\n");
    return 0;
}

int str_chr_conut(FILE *fp,char ch){
    int count = 0;
    int cr;
    while ((cr = getc(fp)) != EOF)
    {
        if (cr == ch)
            count++;
    }
    fclose(fp);
    return count;
}
