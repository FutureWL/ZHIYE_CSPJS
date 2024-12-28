#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "请输入第一个数字: ";
    std::cin >> num1;
    std::cout << "请输入运算符 (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "请输入第二个数字: ";
    std::cin >> num2;

    double result;
    switch (operation) {
    case '+':
        result = num1 + num2;
        std::cout << "结果是: " << result << std::endl;
        break;
    case '-':
        result = num1 - num2;
        std::cout << "结果是: " << result << std::endl;
        break;
    case '*':
        result = num1 * num2;
        std::cout << "结果是: " << result << std::endl;
        break;
    case '/':
        if (num2 == 0) {
            std::cout << "除数不能为零。" << std::endl;
        }
        else {
            result = num1 / num2;
            std::cout << "结果是: " << result << std::endl;
        }
        break;
    default:
        std::cout << "无效的运算符。" << std::endl;
        break;
    }

    return 0;
}