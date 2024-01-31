
#include <stdio.h>
#include <math.h>
#define N 100
void transform(double source[],double target[],int n,double (*ptf)(double z));
double ptf_1(double x);
double ptf_2(double y);

//这题简单来说就是把第一个函数指针指向的数组计算后赋值给第二个，第三个参数表示数组个数，最后是一个函数指针，用于调用函数。
//可能这是我的老毛病了，只要题目说的不够精确，我就很难理解题目的意思，所以这题我也参考了网上的方法。
//这题考察的是对函数指针的运用，放在形参中声明。
//看到别人的写法我就明白了，可能我对题目的理解有些问题，符号化的语言我更容易理解，这也许是我咬文爵字的原因。

int main(void)
{
	int i;
	
	double source[N];
	double target[N];
 
	for(i=0;i<N;i++)        //  初始化原数组
		source[i]=i+100.0;
 
	transform(source,target,N,sin);        // 对原数组进行sin运算，并存入目标数组，显示目标数组
	transform(source,target,N,cos);        // 对原数组进行cos运算，并存入目标数组，显示目标数组
	transform(source,target,N,ptf_1);      // 把原数组元素代入ptf_1函数，返回结果存入目标数组，并显示
	transform(source,target,N,ptf_2);      // 把原数组元素代入ptf_2函数，返回结果存入目标数组，并显示
    getchar();
	return 0;
}
void transform(double source[],double target[],int n,double (*ptf)(double z))  // 把原数元素代入ptf指向的函数，返回值存入目标数组，并显示
{
	int i;
	for(i=0;i<n;i++)
		target[i]=ptf(source[i]);
	printf("Target array:\n");
	for(i=0;i<n;i++)
	    printf("%.2f ",target[i]);
	printf("\n");
}
double ptf_1(double x)
{
	return (x+1.0);
}
double ptf_2(double y)
{
	return (y-1.0);
}
