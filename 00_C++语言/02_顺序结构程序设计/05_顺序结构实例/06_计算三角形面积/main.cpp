#include <iostream>

int main() {
    double base, height;
    std::cout << "�����������εĵ�: ";
    std::cin >> base;
    std::cout << "�����������εĸ�: ";
    std::cin >> height;

    double area = 0.5 * base * height;
    std::cout << "�����ε����Ϊ: " << area << std::endl;

    return 0;
}