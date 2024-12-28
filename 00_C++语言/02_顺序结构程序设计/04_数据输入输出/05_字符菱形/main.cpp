#include <iostream>
#include <iomanip>

int main() {
    char ch;
    std::cout << "请输入一个字符: ";
    std::cin >> ch;

    int size = 5;  // 这里假设菱形的高度（奇数），可以根据需要修改
    for (int i = 1; i <= size; i += 2) {
        // 打印空格
        std::cout << std::setw((size - i) / 2 + 1);
        // 打印字符
        for (int j = 0; j < i; j++) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    for (int i = size - 2; i >= 1; i -= 2) {
        // 打印空格
        std::cout << std::setw((size - i) / 2 + 1);
        // 打印字符
        for (int j = 0; j < i; j++) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    return 0;
}