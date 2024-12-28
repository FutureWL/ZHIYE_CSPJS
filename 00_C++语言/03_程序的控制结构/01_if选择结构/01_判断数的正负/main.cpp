#include <iostream>

int main() {
    int num;
    std::cout << "请输入一个整数: ";
    std::cin >> num;
    if (num > 0) {
        std::cout << num << " 是正数。" << std::endl;
    }
    else if (num < 0) {
        std::cout << num << " 是负数。" << std::endl;
    }
    else {
        std::cout << num << " 是零。" << std::endl;
    }
    return 0;
}