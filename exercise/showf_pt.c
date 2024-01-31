#include <stdio.h>

int main(void){
    float aboat= 3200.0;
    double abet=2.14e9;
    long double dip = 5.32e-9;
    printf("%f can be written %e\n",aboat,aboat);
    printf("And it's %a in hexindeciaml\n",aboat);
    printf("%f can be written %e\n",abet,abet);
    printf("%lf can be written %le",dip,dip);
    getchar();
return 0;
}