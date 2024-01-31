#include <stdio.h>

int main(void){
    printf("type int has size of %zd bytes.\n",sizeof(int));
    printf("type char has size of %zd bytes.\n",sizeof(char));
    printf("type long has size of %zd bytes.\n",sizeof(long));
    printf("type long long has size of %zd bytes\n",sizeof(long long));
    printf("type double has size of %zd bytes\n",sizeof(double));
    printf("type long double has size of %zd bytes\n",sizeof(long double));
    getchar();
    return 0;
}