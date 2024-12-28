#include <iostream>

int main() {
    char ch;
    std::cout << "请输入一个字符: ";
    std::cin >> ch;
    int asciiValue = static_cast<int>(ch);
    if (asciiValue % 2 == 0) {
        std::cout << "字符 '" << ch << "' 的ASCII值 " << asciiValue << " 是偶数。" << std::endl;
    }
    else {
        std::cout << "字符 '" << ch << "' 的ASCII值 " << asciiValue << " 是奇数。" << std::endl;
    }
    return 0;
}