#include <iostream>

int main() {
    int num;
    std::cout << "������һ������: ";
    std::cin >> num;
    if (num > 0) {
        std::cout << num << " ��������" << std::endl;
    }
    else if (num < 0) {
        std::cout << num << " �Ǹ�����" << std::endl;
    }
    else {
        std::cout << num << " ���㡣" << std::endl;
    }
    return 0;
}