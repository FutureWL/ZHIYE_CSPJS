#include <iostream>

int main() {
    double x, y;
    std::cout << "������������ (x, y): ";
    std::cin >> x >> y;

    int position = 0;
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1) {
        if (x == -1 || x == 1 || y == -1 || y == 1) {
            position = 1; // ������������
        }
        else {
            position = 2; // ������������
        }
    }
    else {
        position = 3; // ������������
    }

    switch (position) {
    case 1:
        std::cout << "�����������ϡ�" << std::endl;
        break;
    case 2:
        std::cout << "�����������ڡ�" << std::endl;
        break;
    case 3:
        std::cout << "�����������⡣" << std::endl;
        break;
    }

    return 0;
}