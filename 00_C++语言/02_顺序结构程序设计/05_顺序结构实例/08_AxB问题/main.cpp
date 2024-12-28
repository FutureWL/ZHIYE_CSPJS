#include <iostream>

int main() {
    int a, b;
    std::cout << "请输入两个整数A和B: ";
    std::cin >> a >> b;
    int result = a * b;
    std::cout << "A × B 的结果是: " << result << std::endl;
    return 0;
}