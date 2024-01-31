#include <stdio.h>
#define STLEN 81

int main(void){
    char word[STLEN];

    puts("Enter a string,please");
    gets(word);
    printf("Your string twice:\n");
    printf("%s\n",word);
    puts(word);
    puts("Done!");
    getchar();
    return 0;
}