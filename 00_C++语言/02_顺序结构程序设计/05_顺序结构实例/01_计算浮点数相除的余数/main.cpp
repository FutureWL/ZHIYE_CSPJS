#include <iostream>
#include <cmath>

int main() {
    double num1 = 7.5;
    double num2 = 2.5;
    double result = fmod(num1, num2);
    std::cout << num1 << " 除以 " << num2 << " 的余数是: " << result << std::endl;
    return 0;
}