#include <iostream>
#include <iomanip>

int main() {
    char ch;
    std::cout << "������һ���ַ�: ";
    std::cin >> ch;

    int size = 5;  // ����������εĸ߶ȣ������������Ը�����Ҫ�޸�
    for (int i = 1; i <= size; i += 2) {
        // ��ӡ�ո�
        std::cout << std::setw((size - i) / 2 + 1);
        // ��ӡ�ַ�
        for (int j = 0; j < i; j++) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    for (int i = size - 2; i >= 1; i -= 2) {
        // ��ӡ�ո�
        std::cout << std::setw((size - i) / 2 + 1);
        // ��ӡ�ַ�
        for (int j = 0; j < i; j++) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    return 0;
}