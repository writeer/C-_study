#include <stdio.h>
#include <stdlib.h>

void file_copy(FILE *src,FILE *dest);

int main(int argc, char const *argv[])
{
    FILE *fp,*ft;
    if(argc == 3){
    if ((fp = fopen(argv[1],"rb")) == NULL)
    {
        fprintf(stderr,"Can't open %f file.\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((ft = fopen(argv[2],"wb")) == NULL)
    {
        fprintf(stderr,"Can't create %f file.\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    file_copy(fp,ft);
    if(ferror(fp) != 0)
            fprintf(stderr,"Error in reading file %s.\n",argv[1]);
    if(ferror(ft) != 0)
            fprintf(stderr,"Error in writing file %s.\n",argv[2]);
    if (fclose(fp) != EOF && fclose(ft) != EOF)
        printf("Copy succeeded!\n");
    else
        printf("File close failed\n");
    
    }
    else
        printf("input error\n");
    return 0;
}

void file_copy(FILE *src,FILE *dest){
    size_t bye;
    char temp[4096];
    while ((bye = fread(temp,sizeof(char),4096,src)) > 0)
        fwrite(temp,sizeof(char),bye,dest);
    return;
}