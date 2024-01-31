#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 256

int main(int argc, char const *argv[])
{
    FILE *fp;
    char ch[SLEN];
    if(argc == 3){
        if((fp = fopen(argv[2],"r")) == NULL){
            fprintf(stderr,"Can't open %s file.\n",argv[2]);
            exit(EXIT_FAILURE);
        }
        while (fgets(ch,SLEN-1,fp) != NULL)
        {
            if (strstr(ch,argv[1]))
            {
                fputs(ch,stdout);
            }
            
        }
        
    }
    else
        printf("Input error.\n");
    return 0;
}
