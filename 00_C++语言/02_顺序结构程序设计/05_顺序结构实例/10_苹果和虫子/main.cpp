#include <iostream>

int main() {
    int n, m, k;
    std::cout << "������ƻ�������� n: ";
    std::cin >> n;
    std::cout << "������ÿ��ƻ���ϳ��ӵ����� m: ";
    std::cin >> m;
    std::cout << "�����뱻����ҧ��ƻ������ k: ";
    std::cin >> k;

    if (k > n) {
        std::cout << "������ҧ��ƻ���������ܴ���ƻ����������" << std::endl;
        return 1;
    }

    int remainingApples = n - k;
    int remainingWorms = remainingApples * m;
    std::cout << "û��ҧ��ƻ���ϻ�ʣ�� " << remainingWorms << " �����ӡ�" << std::endl;

    return 0;
}