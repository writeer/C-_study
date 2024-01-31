#include <stdio.h>
#include <string.h>
//strcat()拼接两个字符串

#include "s_gets.c"

#define SIZE 80

int main(void){
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    puts("What is your favorite flower?");
    if (s_gets(flower,SIZE))
    {
        strcat(flower,addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    puts("Bye!");
    getchar();
    return 0;
}

