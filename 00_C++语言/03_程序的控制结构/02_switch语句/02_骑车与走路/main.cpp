#include <iostream>

int main() {
    double v1, v2, s;
    std::cout << "请输入走路速度 v1(单位: m/s): ";
    std::cin >> v1;
    std::cout << "请输入骑车速度 v2(单位: m/s): ";
    std::cin >> v2;
    std::cout << "请输入路程 s(单位: m): ";
    std::cin >> s;

    if (v1 <= 0 || v2 <= 0 || s <= 0) {
        std::cout << "输入的速度或路程不能为负数或零。" << std::endl;
        return 1;
    }

    double walkTime = s / v1;
    double bikeTime = s / v2;

    std::cout << "走路需要的时间为: " << walkTime << " 秒" << std::endl;
    std::cout << "骑车需要的时间为: " << bikeTime << " 秒" << std::endl;

    if (walkTime < bikeTime) {
        std::cout << "走路用时更短。" << std::endl;
    }
    else if (walkTime > bikeTime) {
        std::cout << "骑车用时更短。" << std::endl;
    }
    else {
        std::cout << "走路和骑车用时相同。" << std::endl;
    }

    return 0;
}