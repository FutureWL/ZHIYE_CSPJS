#include <iostream>

int main() {
    int x;
    std::cout << "������һ������ x: ";
    std::cin >> x;

    int condition = 0;
    if (x < 0) {
        condition = -1;
    }
    else if (x > 0) {
        condition = 1;
    }

    int y;
    switch (condition) {
    case -1:
        y = -1;
        break;
    case 0:
        y = 0;
        break;
    case 1:
        y = 1;
        break;
    }

    std::cout << "�� x = " << x << " ʱ��y = " << y << std::endl;

    return 0;
}