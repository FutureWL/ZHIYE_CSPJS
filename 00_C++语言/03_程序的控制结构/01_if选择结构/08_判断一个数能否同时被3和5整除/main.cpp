#include <iostream>

int main() {
    int num;
    std::cout << "������һ������: ";
    std::cin >> num;

    if (num % 3 == 0 && num % 5 == 0) {
        std::cout << num << " ��ͬʱ�� 3 �� 5 ������" << std::endl;
    }
    else {
        std::cout << num << " ����ͬʱ�� 3 �� 5 ������" << std::endl;
    }

    return 0;
}