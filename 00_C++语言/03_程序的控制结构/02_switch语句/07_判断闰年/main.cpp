#include <iostream>

int main() {
    int year;
    std::cout << "������һ�����: ";
    std::cin >> year;

    int isLeapYear = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = 1;
    }

    switch (isLeapYear) {
    case 1:
        std::cout << year << " �����ꡣ" << std::endl;
        break;
    default:
        std::cout << year << " �������ꡣ" << std::endl;
        break;
    }

    return 0;
}