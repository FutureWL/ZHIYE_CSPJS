#include <iostream>

int main() {
    int weight;
    std::cout << "�����������������λ���ˣ���";
    std::cin >> weight;

    if (weight <= 0) {
        std::cout << "��������Ϊ�������㡣" << std::endl;
        return 1;
    }

    int baseWeight = 1000;
    int basePrice = 8;
    int additionalPrice = 5;

    int interval = (weight - 1) / 1000;
    int postage;

    switch (interval) {
    case 0:
        postage = basePrice;
        break;
    case 1:
        postage = 12;
        break;
    case 2:
        postage = 18;
        break;
    default:
        postage = basePrice + additionalPrice * (interval - 1);
        break;
    }

    std::cout << "����Ϊ��" << postage << " Ԫ" << std::endl;

    return 0;
}