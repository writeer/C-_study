#include <stdio.h>
#include <stdbool.h>

bool BinarySearch(int * pt,int n,int number);

int main(void)
{
    int numbers[1000];
    for (int i = 0; i < 1000; i++)//生成一个有序数列
    {
        numbers[i] = i + 1;
    }
    if(BinarySearch(numbers,1000,25))//随便选一个数
        printf("你要找的数在数组中。\n");
    else
        printf("你要找的数不在数组中。\n");
    getchar();
    return 0;
}

bool BinarySearch(int * pt,int n,int number)
{
     int low = 0;
        int high = n - 1;
        while (low <= high) {
            //中间位置计算,low+ 最高位置减去最低位置,右移一位,相当于除2.也可以用(high+low)/2
            int middle = (high+low)/2;//low + ((high - low) >> 1);
            // int middle=(low+high)/2;
            //与最中间的数字进行判断,是否相等,相等的话就返回对应的数组下标.
            if (number == pt[middle]) {
                return middle;
                //如果小于的话则移动最高层的"指针"
            } else if (number < pt[middle]) {
                high = middle - 1;
                //移动最低的"指针"
            } else {
                low = middle + 1;
            }
        }
        return false;
}