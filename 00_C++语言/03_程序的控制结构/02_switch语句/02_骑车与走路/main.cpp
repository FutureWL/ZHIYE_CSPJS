#include <iostream>

int main() {
    double v1, v2, s;
    std::cout << "��������·�ٶ� v1(��λ: m/s): ";
    std::cin >> v1;
    std::cout << "�������ﳵ�ٶ� v2(��λ: m/s): ";
    std::cin >> v2;
    std::cout << "������·�� s(��λ: m): ";
    std::cin >> s;

    if (v1 <= 0 || v2 <= 0 || s <= 0) {
        std::cout << "������ٶȻ�·�̲���Ϊ�������㡣" << std::endl;
        return 1;
    }

    double walkTime = s / v1;
    double bikeTime = s / v2;

    std::cout << "��·��Ҫ��ʱ��Ϊ: " << walkTime << " ��" << std::endl;
    std::cout << "�ﳵ��Ҫ��ʱ��Ϊ: " << bikeTime << " ��" << std::endl;

    if (walkTime < bikeTime) {
        std::cout << "��·��ʱ���̡�" << std::endl;
    }
    else if (walkTime > bikeTime) {
        std::cout << "�ﳵ��ʱ���̡�" << std::endl;
    }
    else {
        std::cout << "��·���ﳵ��ʱ��ͬ��" << std::endl;
    }

    return 0;
}