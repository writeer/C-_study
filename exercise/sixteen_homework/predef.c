//预定义宏和预定义标识符
#include <stdio.h>
void why_me();

int main(void){
    printf("The file is %s.\n",__FILE__);
    printf("The date is %s.\n",__DATE__);
    printf("The time is %s.\n",__TIME__);
#line 458
    printf("The is line %d.\n",__LINE__);
    printf("The function %s.\n",__func__);
    #error Nobody can compile this program
    printf("The version is %ld.\n",__STDC_VERSION__);
   
    why_me();

    return 0;
}

void why_me(){
    printf("This function is %s\n",__func__);
    printf("This is line %d",__LINE__);
}