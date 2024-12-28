#include <iostream>

int main() {
    int exponent;
    std::cout << "请输入指数: ";
    std::cin >> exponent;

    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 2;
    }

    std::cout << "2 的 " << exponent << " 次幂是: " << result << std::endl;
    return 0;
}