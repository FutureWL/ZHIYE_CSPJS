#include <iostream>

// ����Ȳ�����ĩ��ĺ���
int calculateLastTerm(int a1, int d, int n) {
    return a1 + (n - 1) * d;
}

int main() {
    int firstTerm, commonDifference, numberOfTerms;
    std::cout << "������Ȳ����е�����: ";
    std::cin >> firstTerm;
    std::cout << "������Ȳ����еĹ���: ";
    std::cin >> commonDifference;
    std::cout << "����������: ";
    std::cin >> numberOfTerms;

    int lastTerm = calculateLastTerm(firstTerm, commonDifference, numberOfTerms);
    std::cout << "�õȲ����е�ĩ��Ϊ: " << lastTerm << std::endl;

    return 0;
}