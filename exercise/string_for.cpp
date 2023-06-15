#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "Hello word";
    for(char &c : s1)
    {
        c = 'X';
    }
    cout << s1 << endl;
    system("pause");
    return 0;
}