#include <iostream>
#include <vector>

using namespace std;

int add(int one,int two);
int sub(int one,int two);
int mul(int one,int two);
int divl(int one,int two);


int main(){
    vector<decltype(add) * > vec = {add,sub,mul,divl};
    int num = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        num = (*it)(5,5);
        cout << num << endl;
    }
    
    
    system("pause");
    return 0;
}



int add(int one,int two){return one + two;}
int sub(int one,int two){return one - two;}
int mul(int one,int two){return one * two;}
int divl(int one,int two){return one / two;}