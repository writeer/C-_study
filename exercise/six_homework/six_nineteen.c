#include <stdio.h>
#define SIZE 10
#define PAR 72

int main(void){
    int index,score[SIZE];
    int sum = 0;
    float average;

    printf("Enter %d golf score:\n",SIZE);
    for(index = 0;index < SIZE;index++)//读取十个分数，只要数字中间用空格或者回车隔开，它会自动识别，非常智能和方便，并不向写出来的那样需要一个一个输入
        scanf("%d",&score[index]);
    printf("The score read in are as follows:\n");
    for(index = 0;index < SIZE;index++)
        printf("%5d",score[index]);
    printf("\n");
    for (index = 0;index<SIZE;index++)
        sum +=score[index];
    average = (float)sum / SIZE;
    printf("Sum of score = %d,ave = %.2f\n",sum,average);
    printf("That's a handicap of %.0f.\n",average - PAR);
    fflush(stdin);
    getchar();
    return 0;
}