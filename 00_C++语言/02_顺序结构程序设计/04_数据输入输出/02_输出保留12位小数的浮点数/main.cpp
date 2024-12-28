#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979323846;
    // 使用 fixed 以固定小数形式输出，setprecision 设置小数位数为12
    std::cout << std::fixed << std::setprecision(12) << num << std::endl;

    return 0;
}