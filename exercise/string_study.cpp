#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1,str,space;
    while (cin >> s1)
    {
        if(s1 == "q")
            break;
        str += s1;
        space += ' ' + s1;
    }
    
    cout << str << space << endl;
    system("pause");
    return 0;
}