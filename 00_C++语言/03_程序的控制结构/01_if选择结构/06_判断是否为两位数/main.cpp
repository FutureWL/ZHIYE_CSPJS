#include <iostream>

int main() {
    int number;
    std::cout << "������һ������: ";
    std::cin >> number;

    if (number >= 10 && number <= 99) {
        std::cout << number << " ����λ����" << std::endl;
    }
    else {
        std::cout << number << " ������λ����" << std::endl;
    }

    return 0;
}