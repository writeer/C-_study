#include <stdio.h>
int Temperatures(double hua);
int main(void){
    double hua;//华氏度
    int num;
    printf("这是一个转换华氏度的程序\n");
    num = 1;
    while (num == 1)
    {
    printf("请输入华氏度(输入任何非数字字符退出):");
    num = scanf("%lf",&hua);
    Temperatures(hua);
    }
    return 0;
}

int Temperatures(double hua){
    double she,kai;//摄氏度和开氏度
    const double num = 273.16,numt=32.0;
    she = 5.0 / 9.0 * (hua - numt);
    kai = she + num;
    printf("H = %.2f℉ ,S = %.2f℃ ,K = %.2fK\n",hua,she,kai);
    return 0;
}