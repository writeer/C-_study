#include <stdio.h>
#include <string.h>

int main(void){
    char character[255];
    int number,i;
  
    printf("这个代码会读取下一行的内容:\n");
    for (i = 0; character[i-1] != '\n'; i++)
    {
        scanf("%c",&character[i]);
    }
    character[i] = '\0';//所以我在最后一位上添加\0用作strlen的字符判断
    number = strlen(character);//-strlen(character)/2;
    //printf("%d",number);经过测试，发现strlen计算出的值比输入值多一倍，这应该是因为字符末尾没有\0结尾，所以strlen不好判断结束位置。
    for (int j = number-2; j >= 0; j--)//减2的原因是要过滤掉\0和换行，这样打印出来会更整齐。
    {
        printf("%c",character[j]);
    }
    fflush(stdin);
    getchar();
    return 0;
}
//经过这个代码的学习，比在书上更好的了解了strlen函数。