#include <stdio.h>
#include <ctype.h>

int see_al(char);

int main(){
    char ch;
    int ch_num;
    while ((ch = getchar()) != EOF)
    {
        ch_num = see_al(ch);
        if (ch_num != -1)
        {
            printf("%d ",ch_num);
        }
        
    }
    return 0;
}

int see_al(char ch){
    if (isalpha(ch) != 0)
    {
        if (islower(ch) != 0)
        {
           ch = toupper(ch);
           return (ch - 64);
        }
        else
            return (ch - 64);
    }
    else
        return -1;
}
