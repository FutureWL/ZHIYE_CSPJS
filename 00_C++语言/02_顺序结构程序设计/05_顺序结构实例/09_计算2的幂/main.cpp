#include <iostream>

int main() {
    int exponent;
    std::cout << "������ָ��: ";
    std::cin >> exponent;

    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 2;
    }

    std::cout << "2 �� " << exponent << " ������: " << result << std::endl;
    return 0;
}