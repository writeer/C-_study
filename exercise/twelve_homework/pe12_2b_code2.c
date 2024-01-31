#include <stdio.h>
#include "pe12-2a.h"

int main(void){
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode:");
    scanf("%d",&mode);
    while(mode >= 0){
        set_mode(mode);//判断输入
        get_info();//获取数值
        show_info();//显示
        printf("Enter 0 for metric mode, 1 for US mode");
        printf("(-1 to quit):");
        scanf("%d",&mode);
    }
    printf("Done!\n");
    return 0;
}