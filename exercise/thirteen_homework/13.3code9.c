#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void){
    FILE * fp,*fa;
    int count;
    char words[MAX];
     if ((fa = fopen("number.txt","r+")) == NULL)
    {
        fprintf(stdout,"Can't open \"number.txt\" file.\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen("wordy","a+")) == NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    if (fscanf(fa,"%d",&count) == EOF)
        {
            fprintf(stderr,"file does not exist");
            exit(EXIT_FAILURE);
        }
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%40s",words) == 1 && (words[0] != '#'))){
        count++;
        fprintf(fp,"%d: %s\n",count,words);
    }
    fprintf(fa,"%d",count);
    puts("Flie contents:");
    rewind(fp);
    while ((fscanf(fp,"%s",words)) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file!\n");
    fclose(fa);
    return 0;
}