#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

int main() {
    // ������İ뾶
    const double radius = 5.0;
    // ����������
    double volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    std::cout << "�뾶Ϊ " << radius << " ����������: " << volume << std::endl;
    return 0;
}