#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "�����������������Կո�ָ�: ";
    std::cin >> num1 >> num2 >> num3;

    int maxIndex = 0;
    if (num2 > num1) {
        if (num2 > num3) {
            maxIndex = 2;
        }
        else {
            maxIndex = 3;
        }
    }
    else {
        if (num1 > num3) {
            maxIndex = 1;
        }
        else {
            maxIndex = 3;
        }
    }

    int maxNumber;
    switch (maxIndex) {
    case 1:
        maxNumber = num1;
        break;
    case 2:
        maxNumber = num2;
        break;
    case 3:
        maxNumber = num3;
        break;
    }

    std::cout << "��������: " << maxNumber << std::endl;

    return 0;
}