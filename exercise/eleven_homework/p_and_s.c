#include <stdio.h>

int main(void){
    const char * mesg = "Don't be a fool";
    const char * copy;
    copy = mesg;
    printf("mesg = %s,&mesg = %p,value = %p,*mesg = %p\n",mesg,&mesg,mesg);//他们指向的地址是一样的，但是他们本身的指针储存地址却不相同。
    printf("copy = %s,&copy = %p,value = %p,*copy = %p\n",copy,&copy,copy);
    getchar();
    return 0;
}