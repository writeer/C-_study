
static unsigned long int next = 1;//种子

unsigned int rand0(void){

    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

//用于重置种子，先通过这个函数改变next的值，然后上面那个函数获取到的就是新值
void srand1(unsigned int seed)
{
    next = seed;
}