#include <iostream>

int main() {
    int number;
    std::cout << "请输入一个三位数: ";
    std::cin >> number;

    if (number >= 100 && number <= 999) {
        int units = number % 10;
        int tens = (number / 10) % 10;
        int hundreds = number / 100;

        int reversedNumber = units * 100 + tens * 10 + hundreds;
        std::cout << "反向后的数字是: " << reversedNumber << std::endl;
    }
    else {
        std::cout << "输入的不是一个三位数。" << std::endl;
    }

    return 0;
}