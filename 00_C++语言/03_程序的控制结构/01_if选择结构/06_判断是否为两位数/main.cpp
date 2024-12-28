#include <iostream>

int main() {
    int number;
    std::cout << "请输入一个整数: ";
    std::cin >> number;

    if (number >= 10 && number <= 99) {
        std::cout << number << " 是两位数。" << std::endl;
    }
    else {
        std::cout << number << " 不是两位数。" << std::endl;
    }

    return 0;
}