#include <stdio.h>

int main(void){
const double RENT = 3852.99;
printf("*%f*\n",RENT);
printf("*%e*\n",RENT);
printf("*%4.2f*\n",RENT);
printf("*%3.1f*\n",RENT);
printf("*%10.3f*\n",RENT);//加负号左对齐
printf("*%10.3e*\n",RENT);
printf("*%+4.2f*\n",RENT);
printf("*%010.2f*\n",RENT);
getchar();
return 0;
}