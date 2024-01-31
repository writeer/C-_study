#include <stdio.h>
#include <ctype.h>

int main(void){
    char ch;
    int words,pun,capital,mins,num;
    words = pun = capital = mins = num = 0;
    while ((ch = getchar()) != EOF)
    {
        if (isspace(ch) != 0)
           words++;
        if (isupper(ch) != 0)
            capital++;
        if(islower(ch) != 0)
            mins++;
        if (ispunct(ch) != 0)
            pun++;
        if (isdigit(ch) != 0)
            num++;
        
    }
    printf("words = %d, punctuation = %d, capital = %d, minuscules = %d, number = %d \n",words,pun,capital,mins,num);
    return 0;
}