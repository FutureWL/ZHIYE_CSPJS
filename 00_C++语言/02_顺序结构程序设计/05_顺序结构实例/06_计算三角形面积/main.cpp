#include <iostream>

int main() {
    double base, height;
    std::cout << "请输入三角形的底: ";
    std::cin >> base;
    std::cout << "请输入三角形的高: ";
    std::cin >> height;

    double area = 0.5 * base * height;
    std::cout << "三角形的面积为: " << area << std::endl;

    return 0;
}