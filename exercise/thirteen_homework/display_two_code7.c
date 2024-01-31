#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp,*fa;
    char *bol,*bot;//分别判断每个文件是否到结尾
    int ch,gc;
    char name[10];
    char buf[256];
    char buff[256];
    if(argc == 3){
        if((fp = fopen(argv[1],"r")) == NULL){
            fprintf(stderr,"Can't open %s file.\n",argv[1]);
            exit(EXIT_FAILURE);
        }
        if ((fa = fopen(argv[2],"r")) == NULL)
        {
            fprintf(stderr,"Can't open %s file.\n",argv[2]);
            exit(EXIT_FAILURE);
        }
    }else{
        puts("Enter you first filename.");
        fscanf(stdin,"%9s",name);
         if((fp = fopen(name,"r")) == NULL){
            fprintf(stderr,"Can't open %s file.\n",name);
            exit(EXIT_FAILURE);
        }
        puts("Enter you second filename.");
        fscanf(stdin,"%9s",name);
         if((fa = fopen(name,"r")) == NULL){
            fprintf(stderr,"Can't open %s file.\n",name);
            exit(EXIT_FAILURE);
        }
    }
    while (bol != NULL|| bot != NULL)
    {
        if((bol = fgets(buf,256,fp)) != NULL)
            fputs(buf,stdout);
        if((bot = fgets(buff,256,fa)) != NULL)
            fputs(buff,stdout);
    }
    fclose(fp);
    fclose(fa);

    return 0;
}
