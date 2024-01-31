#include <stdio.h>

#define HARMONIC(x,y) 1 / (((1 / x) + (1 / y)) / 2)

int main(void)
{
    double nub = 52.0,cc = 65.0;
    double avg;
    avg = HARMONIC(nub,cc);
    printf("avg = %lf.\n",avg);

    getchar();
    return 0;
}