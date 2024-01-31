#include <stdio.h>
#include <string.h>

int main(void){
    char foot[] = "Yummy";
    char * ptr;

    ptr = foot + strlen(foot);
    while(--ptr >= foot)
        puts(ptr);
    getchar();
    return 0;
}