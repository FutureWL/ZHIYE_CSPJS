#include <iostream>
#include <iomanip>

int main() {
    double number = 123.456789;
    // ʹ��fixed��ʾ�Թ̶�С��������ʾ
    // setprecision(3) ����С��λ��Ϊ3
    std::cout << std::fixed << std::setprecision(3) << number << std::endl;

    return 0;
}