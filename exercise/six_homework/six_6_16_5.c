#include <stdio.h>

int main(void){
    char character;
    int asc,dsc;
    printf("Enter a character:");
    /*这个代码可以输出
       A
      ABA
     ABCBA
     这样的图像，图像输出取决于你输入的字母，从A开始到你输入的字母结束。 
    */
    scanf("%C",&character);
    for (int i = 'A'; i <= character; i++)//控制字符个数，ascll码中A是65，小a是97，所以ascll码表越后面的，这个图像越大，最高127，可以输个波浪号玩玩。
    {
        for (int space = i; space <= character; space++)
        {
            printf(" ");
        }//控制空格
        
        for (asc = 'A'; asc <= i; asc++)//升序asc
        {
            printf("%c",asc);
        }

        for (dsc = asc-2; dsc >= 'A'; dsc--)//降序dsc，直接-2因为上式不符合条件时acs++多加了一，而默认运行一次，所以要多减一。
        {
            printf("%c",dsc);
        }
        printf("\n");
    }
    fflush(stdin);
    getchar();
    return 0;
}