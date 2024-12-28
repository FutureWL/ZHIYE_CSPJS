#include <iostream>

int main() {
    int n, m, k;
    std::cout << "请输入苹果的总数 n: ";
    std::cin >> n;
    std::cout << "请输入每个苹果上虫子的数量 m: ";
    std::cin >> m;
    std::cout << "请输入被虫子咬的苹果数量 k: ";
    std::cin >> k;

    if (k > n) {
        std::cout << "被虫子咬的苹果数量不能大于苹果的总数。" << std::endl;
        return 1;
    }

    int remainingApples = n - k;
    int remainingWorms = remainingApples * m;
    std::cout << "没被咬的苹果上还剩下 " << remainingWorms << " 条虫子。" << std::endl;

    return 0;
}