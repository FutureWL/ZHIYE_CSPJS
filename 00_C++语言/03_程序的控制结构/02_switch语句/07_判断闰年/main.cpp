#include <iostream>

int main() {
    int year;
    std::cout << "请输入一个年份: ";
    std::cin >> year;

    int isLeapYear = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = 1;
    }

    switch (isLeapYear) {
    case 1:
        std::cout << year << " 是闰年。" << std::endl;
        break;
    default:
        std::cout << year << " 不是闰年。" << std::endl;
        break;
    }

    return 0;
}