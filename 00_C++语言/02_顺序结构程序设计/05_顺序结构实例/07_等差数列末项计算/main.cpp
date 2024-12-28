#include <iostream>

// 计算等差数列末项的函数
int calculateLastTerm(int a1, int d, int n) {
    return a1 + (n - 1) * d;
}

int main() {
    int firstTerm, commonDifference, numberOfTerms;
    std::cout << "请输入等差数列的首项: ";
    std::cin >> firstTerm;
    std::cout << "请输入等差数列的公差: ";
    std::cin >> commonDifference;
    std::cout << "请输入项数: ";
    std::cin >> numberOfTerms;

    int lastTerm = calculateLastTerm(firstTerm, commonDifference, numberOfTerms);
    std::cout << "该等差数列的末项为: " << lastTerm << std::endl;

    return 0;
}