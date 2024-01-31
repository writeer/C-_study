#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    double sum = 0,n,i = 0;
    if (argc == 1)
    {
        fp = stdin;
    }
    
    if(argc == 2){
        if((fp  = fopen(argv[1],"r")) == NULL){
            fprintf(stderr,"Can't open file %s",argv[1]);
            exit(EXIT_FAILURE);
        }
    }
      while(fscanf(fp,"%lf",&sum) == 1){
        i += sum;
        n++;
    }
    if(n > 0)
        printf("sum / n = %lf\n",sum / n);
    else 
        printf("No data\n");
    return 0;
}
