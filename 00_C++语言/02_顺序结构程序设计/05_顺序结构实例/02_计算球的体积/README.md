1. **ʹ��`const`������`M_PI`�꣨C++��׼�⣩**
   - ��C++�У���������`<cmath>`���е�`M_PI`������ʾԲ����`��`��ͨ���������ʽ`V = \frac{4}{3}��r^3`������������
```cpp
#include <iostream>
#include <cmath>

int main() {
    // ������İ뾶
    const double radius = 5.0;
    // ����������
    double volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    std::cout << "�뾶Ϊ " << radius << " ����������: " << volume << std::endl;
    return 0;
}
```
   - �����������У�
     - ���ȶ�����һ��`const double`���͵ĳ���`radius`��ʾ��İ뾶����������Ϊ`5.0`��
     - Ȼ������������ʽ���������`std::pow(radius, 3)`���ڼ���뾶��������
     - ���ͨ��`std::cout`�����������

2. **���û���ȡ�뾶��ʹ��`std::format`��C++20�����ϣ�**
   - ���ʾ�������û�������İ뾶����ʹ��C++20�����`<format>`����и�ʽ�������
```cpp
#include <iostream>
#include <cmath>
#include <format>

int main() {
    double radius;
    std::cout << "��������İ뾶: ";
    std::cin >> radius;
    double volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    std::cout << std::format("�뾶Ϊ {:.2f} ����������: {:.4f}\n", radius, volume);
    return 0;
}
```
   - ����������У�
     - ������ʾ�û�������İ뾶����������ֵ�洢��`radius`�����С�
     - ����������ķ�ʽ����һ��ʾ����ͬ��
     - ʹ��`std::format`�������и�ʽ�������`{:.2f}`��ʾ���뾶���Ϊ������λС���ĸ�������`{:.4f}`��ʾ��������Ϊ������λС���ĸ�������

3. **���Ǿ��Ⱥ�����ѡ��**
   - �����Ҫ���ߵľ��ȣ�����ʹ��`long double`���͡�
```cpp
#include <iostream>
#include <cmath>

int main() {
    long double radius = 5.0L;
    long double volume = (4.0L / 3.0L) * std::acos(-1.0L) * std::pow(radius, 3);
    std::cout << "�뾶Ϊ " << radius << " ����������: " << volume << std::endl;
    return 0;
}
```
   - ����ʹ��`long double`���ͣ�`std::acos(-1.0L)`���ڻ�ȡ`��`��`long double`��ʾ������Ӧ`long double`���͵ļ��㣬�Ӷ���߾��ȡ�

��Щʾ��չʾ����C++�м���������Ĳ�ͬ����������Ը���ʵ������ѡ����ʵ�ʵ�֡� 