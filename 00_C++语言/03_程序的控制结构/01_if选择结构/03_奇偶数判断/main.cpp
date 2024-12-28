#include <iostream>

int main() {
    int num;
    std::cout << "请输入一个整数: ";
    std::cin >> num;

    if (num % 2 == 0) {
        std::cout << num << " 是偶数" << std::endl;
    }
    else {
        std::cout << num << " 是奇数" << std::endl;
    }

    return 0;
}