#include <iostream>
#include <cmath>
#include <complex>

int main() {
    double a, b, c;
    std::cout << "������һԪ���η��� ax^2 + bx + c = 0 ��ϵ�� a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "a ����Ϊ 0���ⲻ��һԪ���η��̡�" << std::endl;
        return 1;
    }

    double discriminant = b * b - 4 * a * c;
    int rootCase;
    if (discriminant > 0) {
        rootCase = 1;
    }
    else if (discriminant == 0) {
        rootCase = 2;
    }
    else {
        rootCase = 3;
    }

    switch (rootCase) {
    case 1: {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "������������ͬ��ʵ��: " << std::endl;
        std::cout << "x1 = " << root1 << std::endl;
        std::cout << "x2 = " << root2 << std::endl;
        break;
    }
    case 2: {
        double root = -b / (2 * a);
        std::cout << "������һ��ʵ��: " << std::endl;
        std::cout << "x = " << root << std::endl;
        break;
    }
    case 3: {
        std::complex<double> root1(-b / (2 * a), sqrt(-discriminant) / (2 * a));
        std::complex<double> root2(-b / (2 * a), -sqrt(-discriminant) / (2 * a));
        std::cout << "�������������: " << std::endl;
        std::cout << "x1 = " << root1 << std::endl;
        std::cout << "x2 = " << root2 << std::endl;
        break;
    }
    }

    return 0;
}