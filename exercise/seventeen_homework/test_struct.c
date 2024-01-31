#include <stdio.h>

struct  test
{
    int k;
    int b;
};

void show(struct test * tp);

int main(void)
{
    struct test Test = {9,8};
    show(&Test);
    getchar();
    return 0;
}

void show(struct test * tp)
{
    printf("%d %d\n",(*tp).b,(*tp).k);
}