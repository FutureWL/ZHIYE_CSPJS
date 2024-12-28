#include <iostream>
#include <cmath>

int main() {
    double side1, side2, side3;
    std::cout << "请输入三角形的三条边的长度: ";
    std::cin >> side1 >> side2 >> side3;

    // 检查输入是否合法（边长大于0）
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        std::cout << "边长必须为正数。" << std::endl;
        return 1;
    }

    // 判断是否能构成三角形
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        std::cout << "无法构成三角形。" << std::endl;
        return 1;
    }

    int triangleType = 0;
    if (std::abs(side1 - side2) < 1e - 9 && std::abs(side2 - side3) < 1e - 9) {
        triangleType = 1; // 等边三角形
    }
    else if (std::abs(side1 - side2) < 1e - 9 || std::abs(side1 - side3) < 1e - 9 || std::abs(side2 - side3) < 1e - 9) {
        triangleType = 2; // 等腰三角形
    }
    else {
        triangleType = 3; // 一般三角形
    }

    switch (triangleType) {
    case 1:
        std::cout << "这是一个等边三角形。" << std::endl;
        break;
    case 2:
        std::cout << "这是一个等腰三角形。" << std::endl;
        break;
    case 3:
        std::cout << "这是一个一般三角形。" << std::endl;
        break;
    }

    return 0;
}