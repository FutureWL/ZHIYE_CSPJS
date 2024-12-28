#include <iostream>

int main() {
    double x, y;
    std::cout << "请输入点的坐标 (x, y): ";
    std::cin >> x >> y;

    int position = 0;
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1) {
        if (x == -1 || x == 1 || y == -1 || y == 1) {
            position = 1; // 点在正方形上
        }
        else {
            position = 2; // 点在正方形内
        }
    }
    else {
        position = 3; // 点在正方形外
    }

    switch (position) {
    case 1:
        std::cout << "点在正方形上。" << std::endl;
        break;
    case 2:
        std::cout << "点在正方形内。" << std::endl;
        break;
    case 3:
        std::cout << "点在正方形外。" << std::endl;
        break;
    }

    return 0;
}