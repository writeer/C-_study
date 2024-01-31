#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    int ch;
    for (int i = 1; i < argc; i++)
    {
        if((fp = fopen(argv[i],"r")) == NULL){
            printf("Can't open %s file.\n",argv[i]);
            exit(EXIT_FAILURE);
        }
        rewind(fp);
        while((ch = getc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }
    
    return 0;
}
