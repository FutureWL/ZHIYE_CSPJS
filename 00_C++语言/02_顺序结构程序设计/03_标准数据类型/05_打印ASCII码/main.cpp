#include <iostream>
#include <iomanip>

int main() {
    std::cout << "ASCII码表：" << std::endl;
    std::cout << std::left << std::setw(10) << "ASCII码值" << "字符" << std::endl;
    for (int i = 0; i < 128; ++i) {
        if (i % 16 == 0) {
            std::cout << std::endl;
        }
        char ch = static_cast<char>(i);
        if (isprint(ch)) {
            std::cout << std::left << std::setw(10) << i << ch << " ";
        }
        else {
            std::cout << std::left << std::setw(10) << i << "控制字符" << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}