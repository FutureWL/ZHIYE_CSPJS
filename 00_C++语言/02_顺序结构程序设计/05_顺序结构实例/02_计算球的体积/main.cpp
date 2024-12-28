#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

int main() {
    // 定义球的半径
    const double radius = 5.0;
    // 计算球的体积
    double volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    std::cout << "半径为 " << radius << " 的球的体积是: " << volume << std::endl;
    return 0;
}