#include <iostream>

int main() {
    int number;
    std::cout << "������һ������: ";
    std::cin >> number;

    if (number % 3 == 0 && number % 5 == 0 && number % 7 == 0) {
        std::cout << number << " ��ͬʱ�� 3��5 �� 7 ������" << std::endl;
    }
    else {
        std::cout << number << " ����ͬʱ�� 3��5 �� 7 ������" << std::endl;
    }

    return 0;
}