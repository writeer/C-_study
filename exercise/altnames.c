#include <stdio.h>
#include <inttypes.h>//支持可移植类型

int main(void){
    int32_t me32;
    me32 = 45933945;
    printf("first,assume int32_ is int:");
    printf("me32= %d \n",me32);
    printf("Next,Let's not make any assumeprions.\n");
    printf("Instead,use a \"macro\" from inttypes.h:");
    printf("me32 = %" PRId32 " \n",me32);

    return 0;
}
