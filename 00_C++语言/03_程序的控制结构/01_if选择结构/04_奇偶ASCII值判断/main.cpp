#include <iostream>

int main() {
    char ch;
    std::cout << "������һ���ַ�: ";
    std::cin >> ch;
    int asciiValue = static_cast<int>(ch);
    if (asciiValue % 2 == 0) {
        std::cout << "�ַ� '" << ch << "' ��ASCIIֵ " << asciiValue << " ��ż����" << std::endl;
    }
    else {
        std::cout << "�ַ� '" << ch << "' ��ASCIIֵ " << asciiValue << " ��������" << std::endl;
    }
    return 0;
}