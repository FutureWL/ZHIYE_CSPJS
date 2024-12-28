#include <iostream>

int main() {
    int number;
    std::cout << "请输入一个整数: ";
    std::cin >> number;

    if (number % 3 == 0 && number % 5 == 0 && number % 7 == 0) {
        std::cout << number << " 能同时被 3、5 和 7 整除。" << std::endl;
    }
    else {
        std::cout << number << " 不能同时被 3、5 和 7 整除。" << std::endl;
    }

    return 0;
}