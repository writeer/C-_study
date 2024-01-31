#include <stdio.h>
//这是个测试sizeof
//size_t 是unsigned int/long 的别名
int main(void){
    int n = 0;
    size_t intsize;

    intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd \
    bytes;\n",n,sizeof(n),intsize);
    getchar();
return 0;
}