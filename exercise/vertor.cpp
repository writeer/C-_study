#include <iostream>
using namespace std;

struct A
{
    int n;
    A() = default;
    A(int m): n(m) {}
};

int main()
{
    A st(5);
    A* pst = &st;
    
    cout << st.n << endl;   //输出5，st是左值，在该表达式执行完毕后依然存在
    st.n = 6;               //合法，可以对左值赋值
    cout << pst->n << endl; //输出6，pst是左值，在该表达式执行完毕后依然存在
    pst->n = 7;             //合法，可以对左值赋值
    int p = pst->n;
    cout << p << endl;
/*
    cout << A(8).n << endl; //输出8，A(8)是右值，在该表达式执行完毕后被销毁
    A(8).n = 9;             //非法，不能对右值赋值
    pst = &(A(8));          //非法，不能取右值的地址
    */
   system("pause");
    return 0;
}
