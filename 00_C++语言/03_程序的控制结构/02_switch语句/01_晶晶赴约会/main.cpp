#include <iostream>
#include <string>

int main() {
    std::string time;
    std::cout << "������Լ��ʱ�䣨��ʽ����X���ϣ�: ";
    std::cin >> time;

    int dayIndex = -1;
    if (time == "��һ����") {
        dayIndex = 1;
    }
    else if (time == "�ܶ�����") {
        dayIndex = 2;
    }
    else if (time == "��������") {
        dayIndex = 3;
    }
    else if (time == "��������") {
        dayIndex = 4;
    }
    else if (time == "��������") {
        dayIndex = 5;
    }
    else if (time == "��������") {
        dayIndex = 6;
    }
    else if (time == "��������") {
        dayIndex = 7;
    }

    switch (dayIndex) {
    case 1:
    case 3:
    case 5:
        std::cout << "�������Ը�Լ��" << std::endl;
        break;
    default:
        std::cout << "�����޷���Լ��" << std::endl;
        break;
    }

    return 0;