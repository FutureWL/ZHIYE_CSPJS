#include <iostream>
#include <cmath>

// ����������߶γ��ȵĺ���
double calculateSegmentLength(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    double x1, y1, x2, y2;
    std::cout << "�������һ���������(x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "������ڶ����������(x2, y2): ";
    std::cin >> x2 >> y2;

    double length = calculateSegmentLength(x1, y1, x2, y2);
    std::cout << "������߶εĳ���Ϊ: " << length << std::endl;

    return 0;
}