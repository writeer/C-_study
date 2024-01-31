#include <stdio.h>
#include <ctype.h>
/*这个程序统计大小写字符个数*/
int main(void){
    char ch;
    int caps,letter;
    caps = letter = 0;
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch) != 0)
        {
            letter++;
        }
        else if (isupper(ch) != 0)
        {
            caps++;
        }
        else
            continue;
    }
    printf("caps is %d,小写字母 is %d",caps,letter);
    return 0;
}