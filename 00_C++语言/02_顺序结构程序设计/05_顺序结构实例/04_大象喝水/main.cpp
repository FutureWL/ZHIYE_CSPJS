#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    const double PI = 3.14;
    const double NEED_WATER = 20;
    double h, r;
    std::cout << "������ԲͰ�ĸ߶�h(����)�͵���뾶r(����): ";
    std::cin >> h >> r;
    // ����ԲͰ������������ף�
    double volumeCubicCentimeter = PI * r * r * h;
    // �����ת��Ϊ��
    double volumeLiter = volumeCubicCentimeter / 1000;
    // ������Ҫ��Ͱ��������ȡ��
    int bucketCount = std::ceil(NEED_WATER / volumeLiter);
    std::cout << "��������Ҫ�� " << bucketCount << " Ͱˮ�Ż��ʡ�" << std::endl;
    return 0;
}