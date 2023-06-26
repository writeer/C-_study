#include <iostream>

class Screen {
public:
    static const char bkground;

    Screen& clear(char = bkground);
};

const char Screen::bkground = ' ';

Screen& Screen::clear(char c) {
    std::cout << c << std::endl;
    // 使用参数c进行清除操作
    return *this;
}

int main()
{
    Screen mm;
    mm.clear();
    const char *&&f = "hello";
    std::cout << f << std::endl;
    system("pause");
    return 0;
}