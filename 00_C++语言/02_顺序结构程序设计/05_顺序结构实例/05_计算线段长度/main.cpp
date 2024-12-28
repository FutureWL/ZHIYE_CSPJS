#include <iostream>
#include <cmath>

// 计算两点间线段长度的函数
double calculateSegmentLength(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    double x1, y1, x2, y2;
    std::cout << "请输入第一个点的坐标(x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "请输入第二个点的坐标(x2, y2): ";
    std::cin >> x2 >> y2;

    double length = calculateSegmentLength(x1, y1, x2, y2);
    std::cout << "两点间线段的长度为: " << length << std::endl;

    return 0;
}