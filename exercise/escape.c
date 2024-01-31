#include <stdio.h>
#include <Windows.h>

int main(void){
    float salary;
    printf("\aEnter your desired monthly salary:");
    printf("$__________\b\b\b\b\b\b\b\b");
    scanf("%f",&salary);
    printf("\n\t$%.2f a month is $%.2f a year.",salary,salary *12.0);
    getchar();
    printf("\rGee\n");
    getchar();
    system("pause");
return 0;
}