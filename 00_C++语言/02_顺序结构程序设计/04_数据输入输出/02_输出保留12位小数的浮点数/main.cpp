#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979323846;
    // ʹ�� fixed �Թ̶�С����ʽ�����setprecision ����С��λ��Ϊ12
    std::cout << std::fixed << std::setprecision(12) << num << std::endl;

    return 0;
}