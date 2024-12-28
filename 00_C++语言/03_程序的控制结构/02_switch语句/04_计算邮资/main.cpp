#include <iostream>

int main() {
    int weight;
    std::cout << "请输入包裹重量（单位：克）：";
    std::cin >> weight;

    if (weight <= 0) {
        std::cout << "重量不能为负数或零。" << std::endl;
        return 1;
    }

    int baseWeight = 1000;
    int basePrice = 8;
    int additionalPrice = 5;

    int interval = (weight - 1) / 1000;
    int postage;

    switch (interval) {
    case 0:
        postage = basePrice;
        break;
    case 1:
        postage = 12;
        break;
    case 2:
        postage = 18;
        break;
    default:
        postage = basePrice + additionalPrice * (interval - 1);
        break;
    }

    std::cout << "邮资为：" << postage << " 元" << std::endl;

    return 0;
}