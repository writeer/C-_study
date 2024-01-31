#define MSG "I'm special"

#include <stdio.h>

int main(void){
    char ar[] = MSG;
    const char * pr = MSG;
    printf("address of \"I'm special\": %p \n","I'm special");
    printf("address ar: %p\n",ar);
    printf("address pr: %p\n",pr);
    printf("address MSG: %p\n",MSG);
    printf("address of \"I'm special\": %p \n","I'm special");
    getchar();
    return 0;
}