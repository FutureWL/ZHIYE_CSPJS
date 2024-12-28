#include <iostream>

int main() {
    int num1, num2;
    std::cout << "请输入第一个整数: ";
    std::cin >> num1;
    std::cout << "请输入第二个整数: ";
    std::cin >> num2;

    if (num1 > num2) {
        std::cout << num1 << " 大于 " << num2 << std::endl;
    }
    else if (num1 < num2) {
        std::cout << num1 << " 小于 " << num2 << std::endl;
    }
    else {
        std::cout << num1 << " 等于 " << num2 << std::endl;
    }

    return 0;
}