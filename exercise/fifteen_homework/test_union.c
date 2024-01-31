#include <stdio.h>

union test_union
{
    int n;
    double w;
};


int main(void){
    union test_union test = {0};
   /* test.n = 50;
    test.w = 96.56;*/
    //现在是正常显示，然后我调换一下变量赋值顺序。
    test.w = 96.56;
    test.n = 50;
    printf("%d\n",sizeof(long long ));
    printf("%d.\n",test.n);
    //果然，现在就正常显示了。
    //原因在于储存方法，因为union的储存是用的确实一最长那段字节的内存，但不是用新值完全覆盖就值，除非内存大小一致
    //至于原因我在dualview15.4里写过原理
    //所以当先赋值int类型，再赋值double类型，int的值就会被double类型给覆盖掉，因为double类型有八个字节，而int类型只有四个。
    //但是当我先赋值double类型，再赋值int类型时，因为in类型不够，只会覆盖掉四个字节，所以当double类型的值不大，两边就不会相互影响
    //但是因为96.56后面被int类型覆盖了一些，所以会出现一些莫名的数字，这是因为浮点数和整型的储存结构导致的
    //不过也算解决了我上一个代码为什么不同的原因。
    printf("%lf.\n",test.w);
    getchar();
    return 0;
}