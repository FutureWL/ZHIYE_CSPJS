#include <iostream>

int main() {
    int number;
    std::cout << "������һ����λ��: ";
    std::cin >> number;

    if (number >= 100 && number <= 999) {
        int units = number % 10;
        int tens = (number / 10) % 10;
        int hundreds = number / 100;

        int reversedNumber = units * 100 + tens * 10 + hundreds;
        std::cout << "������������: " << reversedNumber << std::endl;
    }
    else {
        std::cout << "����Ĳ���һ����λ����" << std::endl;
    }

    return 0;
}