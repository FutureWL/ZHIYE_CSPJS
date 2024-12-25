#include <iostream>
#include <cmath>

// 手动实现向零舍入
int manualTruncate(double num) {
    if (num >= 0) {
        return static_cast<int>(num);
    }
    else {
        return static_cast<int>(num - 0.999999);
    }
}

int main() {
    double floatNumber = 3.7;
    std::cout << "原始浮点数: " << floatNumber << std::endl;

    // 使用cmath库中的trunc函数进行向零舍入
    double resultUsingTrunc = std::trunc(floatNumber);
    std::cout << "使用trunc函数向零舍入的结果: " << resultUsingTrunc << std::endl;

    // 使用手动实现的函数进行向零舍入
    int resultManual = manualTruncate(floatNumber);
    std::cout << "手动实现向零舍入的结果: " << resultManual << std::endl;

    floatNumber = -2.3;
    std::cout << "\n原始浮点数: " << floatNumber << std::endl;

    resultUsingTrunc = std::trunc(floatNumber);
    std::cout << "使用trunc函数向零舍入的结果: " << resultUsingTrunc << std::endl;

    resultManual = manualTruncate(floatNumber);
    std::cout << "手动实现向零舍入的结果: " << resultManual << std::endl;

    return 0;
}