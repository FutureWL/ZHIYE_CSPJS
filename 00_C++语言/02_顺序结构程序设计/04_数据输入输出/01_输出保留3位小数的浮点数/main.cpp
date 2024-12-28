#include <iostream>
#include <iomanip>

int main() {
    double number = 123.456789;
    // 使用fixed表示以固定小数精度显示
    // setprecision(3) 设置小数位数为3
    std::cout << std::fixed << std::setprecision(3) << number << std::endl;

    return 0;
}