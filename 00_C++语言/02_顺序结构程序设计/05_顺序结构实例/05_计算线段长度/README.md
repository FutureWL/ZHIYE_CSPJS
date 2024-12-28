1. **����ƽ��ֱ������ϵ���������빫ʽ**
   - ��ƽ��ֱ������ϵ�У���֪����\(A(x_1, y_1)\)��\(B(x_2, y_2)\)��������߶εĳ���\(d\)����ͨ����ʽ\(d = \sqrt{(x_2 - x_1)^2+(y_2 - y_1)^2}\)���㡣
   - ������C++ ����ʵ�֣�
```cpp
#include <iostream>
#include <cmath>

// ����������߶γ��ȵĺ���
double calculateSegmentLength(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx+dy * dy);
}

int main() {
    double x1, y1, x2, y2;
    std::cout << "�������һ���������(x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "������ڶ����������(x2, y2): ";
    std::cin >> x2 >> y2;

    double length = calculateSegmentLength(x1, y1, x2, y2);
    std::cout << "������߶εĳ���Ϊ: " << length << std::endl;

    return 0;
}
```
   - �����������У�
     - ������һ������ `calculateSegmentLength`���ú��������ĸ� `double` ���͵Ĳ������ֱ��ʾ����������ꡣ
     - �ں����ڲ����ȼ���������\(x\)���\(y\)�᷽���ϵĲ�ֵ `dx` �� `dy`��Ȼ����ݾ��빫ʽ���㲢�����߶γ��ȡ�
     - �� `main` �����У���ʾ�û���������������꣬���� `calculateSegmentLength` ���������߶γ��ȣ�������������

2. **��ά�ռ���������߶γ���**
   - ����ά�ռ��У���֪����\(A(x_1, y_1, z_1)\)��\(B(x_2, y_2, z_2)\)��������߶εĳ���\(d\)�Ĺ�ʽΪ\(d=\sqrt{(x_2 - x_1)^2+(y_2 - y_1)^2+(z_2 - z_1)^2}\)��
   - �������£�
```cpp
#include <iostream>
#include <cmath>

// ������ά�ռ�������߶γ��ȵĺ���
double calculate3DSegmentLength(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return std::sqrt(dx * dx+dy * dy+dz * dz);
}

int main() {
    double x1, y1, z1, x2, y2, z2;
    std::cout << "�������һ���������(x1, y1, z1): ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "������ڶ����������(x2, y2, z2): ";
    std::cin >> x2 >> y2 >> z2;

    double length = calculate3DSegmentLength(x1, y1, z1, x2, y2, z2);
    std::cout << "��ά�ռ���������߶εĳ���Ϊ: " << length << std::endl;

    return 0;
}
```
   - �˴������ά������ƣ�ֻ��������\(z\)����Ĵ���`calculate3DSegmentLength` ������������������ʾ��ά�ռ�������������꣬������ά�ռ���빫ʽ���㲢�����߶γ��ȡ��� `main` ��������ʾ�û�������ά�ռ�����������꣬���ú������㲢����߶γ��ȡ� 