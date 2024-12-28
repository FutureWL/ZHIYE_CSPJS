#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    const double PI = 3.14;
    const double NEED_WATER = 20;
    double h, r;
    std::cout << "请输入圆桶的高度h(厘米)和底面半径r(厘米): ";
    std::cin >> h >> r;
    // 计算圆桶体积（立方厘米）
    double volumeCubicCentimeter = PI * r * r * h;
    // 将体积转换为升
    double volumeLiter = volumeCubicCentimeter / 1000;
    // 计算需要的桶数并向上取整
    int bucketCount = std::ceil(NEED_WATER / volumeLiter);
    std::cout << "大象至少要喝 " << bucketCount << " 桶水才会解渴。" << std::endl;
    return 0;
}