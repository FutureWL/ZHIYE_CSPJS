#include <iostream>
#include <cmath>

int main() {
    double side1, side2, side3;
    std::cout << "�����������ε������ߵĳ���: ";
    std::cin >> side1 >> side2 >> side3;

    // ��������Ƿ�Ϸ����߳�����0��
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        std::cout << "�߳�����Ϊ������" << std::endl;
        return 1;
    }

    // �ж��Ƿ��ܹ���������
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        std::cout << "�޷����������Ρ�" << std::endl;
        return 1;
    }

    int triangleType = 0;
    if (std::abs(side1 - side2) < 1e - 9 && std::abs(side2 - side3) < 1e - 9) {
        triangleType = 1; // �ȱ�������
    }
    else if (std::abs(side1 - side2) < 1e - 9 || std::abs(side1 - side3) < 1e - 9 || std::abs(side2 - side3) < 1e - 9) {
        triangleType = 2; // ����������
    }
    else {
        triangleType = 3; // һ��������
    }

    switch (triangleType) {
    case 1:
        std::cout << "����һ���ȱ������Ρ�" << std::endl;
        break;
    case 2:
        std::cout << "����һ�����������Ρ�" << std::endl;
        break;
    case 3:
        std::cout << "����һ��һ�������Ρ�" << std::endl;
        break;
    }

    return 0;
}