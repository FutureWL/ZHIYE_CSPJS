#include <iostream>

int main() {
    int num1, num2;
    std::cout << "�������һ������: ";
    std::cin >> num1;
    std::cout << "������ڶ�������: ";
    std::cin >> num2;

    if (num1 > num2) {
        std::cout << num1 << " ���� " << num2 << std::endl;
    }
    else if (num1 < num2) {
        std::cout << num1 << " С�� " << num2 << std::endl;
    }
    else {
        std::cout << num1 << " ���� " << num2 << std::endl;
    }

    return 0;
}