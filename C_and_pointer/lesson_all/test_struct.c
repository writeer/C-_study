#include <stdio.h>

struct {
    int x;
    int y;
} point;

int main() {
    point.x = 10;
    point.y = 20;
    //struct point xy;
    printf("Point coordinates: (%d, %d)\n", point.x, point.y);

    return 0;
}
