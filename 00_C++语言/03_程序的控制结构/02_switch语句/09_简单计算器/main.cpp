#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "�������һ������: ";
    std::cin >> num1;
    std::cout << "����������� (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "������ڶ�������: ";
    std::cin >> num2;

    double result;
    switch (operation) {
    case '+':
        result = num1 + num2;
        std::cout << "�����: " << result << std::endl;
        break;
    case '-':
        result = num1 - num2;
        std::cout << "�����: " << result << std::endl;
        break;
    case '*':
        result = num1 * num2;
        std::cout << "�����: " << result << std::endl;
        break;
    case '/':
        if (num2 == 0) {
            std::cout << "��������Ϊ�㡣" << std::endl;
        }
        else {
            result = num1 / num2;
            std::cout << "�����: " << result << std::endl;
        }
        break;
    default:
        std::cout << "��Ч���������" << std::endl;
        break;
    }

    return 0;
}