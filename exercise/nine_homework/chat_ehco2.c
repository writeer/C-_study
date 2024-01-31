#include <stdio.h>
/*打印输入的字符i行，j列*/
int chline(char,int,int);

int main(void){
    char ch;
    int row,col;//行，列
    printf("Enter a character and tow numbers\n");
    printf("first charter,second row,third col :\n");
    scanf("%c %d %d",&ch,&row,&col);
    chline(ch,row,col);
    return 0;
}

int chline(char ch,int i,int j){
    for (int n = 0; n < i; n++)
    {
        for (int m = 0; m < j; m++)
        {
            putchar(ch);
        }
        printf("\n");
    }
    fflush(stdin);
    getchar();
    return 0;
}