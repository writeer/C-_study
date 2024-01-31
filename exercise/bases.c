#include <stdio.h>
#include <Windows.h>

int main(void){
    int ten=100;

    printf("dec = %d, octal= %o, hex= %x\n",ten,ten,ten);
    printf("dec = %#d, octal= %#o, hex= %#x\n",ten,ten,ten);
    system("pause");
    return 0;
}