1. **��������**��
   - ����һԪ���η��� \(ax^2 + bx + c = 0\)��\(a\neq0\)�������б�ʽ \(\Delta = b^2 - 4ac\)������ \(\Delta\) ��ֵ��ȷ�����̸��������
     - �� \(\Delta > 0\) ʱ��������������ͬ��ʵ�� \(x_1=\frac{-b + \sqrt{\Delta}}{2a}\) �� \(x_2=\frac{-b - \sqrt{\Delta}}{2a}\)��
     - �� \(\Delta = 0\) ʱ��������һ��ʵ�� \(x = -\frac{b}{2a}\)��
     - �� \(\Delta < 0\) ʱ��������������� \(x_1 = -\frac{b}{2a} + i\frac{\sqrt{-\Delta}}{2a}\) �� \(x_2 = -\frac{b}{2a} - i\frac{\sqrt{-\Delta}}{2a}\)��
   - ���ǽ�ʹ�� `switch` ��������� \(\Delta\) �Ĳ�ͬ������д���
2. **����ʵ��**��
```cpp
#include <iostream>
#include <cmath>
#include <complex>

int main() {
    double a, b, c;
    std::cout << "������һԪ���η��� ax^2 + bx + c = 0 ��ϵ�� a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "a ����Ϊ 0���ⲻ��һԪ���η��̡�" << std::endl;
        return 1;
    }

    double discriminant = b * b - 4 * a * c;
    int rootCase;
    if (discriminant > 0) {
        rootCase = 1;
    } else if (discriminant == 0) {
        rootCase = 2;
    } else {
        rootCase = 3;
    }

    switch (rootCase) {
    case 1: {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "������������ͬ��ʵ��: " << std::endl;
        std::cout << "x1 = " << root1 << std::endl;
        std::cout << "x2 = " << root2 << std::endl;
        break;
    }
    case 2: {
        double root = -b / (2 * a);
        std::cout << "������һ��ʵ��: " << std::endl;
        std::cout << "x = " << root << std::endl;
        break;
    }
    case 3: {
        std::complex<double> root1(-b / (2 * a), sqrt(-discriminant) / (2 * a));
        std::complex<double> root2(-b / (2 * a), -sqrt(-discriminant) / (2 * a));
        std::cout << "�������������: " << std::endl;
        std::cout << "x1 = " << root1 << std::endl;
        std::cout << "x2 = " << root2 << std::endl;
        break;
    }
    }

    return 0;
}
```
3. **����˵��**��
   - **��������**��
     - `a`��`b`��`c` ���ڴ洢һԪ���η��̵�ϵ����
     - `discriminant` ���ڴ洢�б�ʽ \(\Delta\) ��ֵ��
     - `rootCase` ���ڱ�Ǹ������������ \(\Delta\) ��ֵȷ����1 ��ʾ��������ͬʵ����2 ��ʾ��һ��ʵ����3 ��ʾ�����������
   - **�����ȡ��Ϸ��Լ��**��
     - ʹ�� `std::cout` ��ʾ�û����뷽�̵�ϵ�� `a`��`b`��`c`����ͨ�� `std::cin` ��ȡ����ֵ��
     - ��� `a` �Ƿ�Ϊ 0������������������Ϣ������������Ϊ��ʱ����һԪ���η��̡�
   - **�����б�ʽ��ȷ���������**��
     - �����б�ʽ `discriminant`��
     - ���� `discriminant` ��ֵȷ�� `rootCase` ��ֵ��
   - **`switch` ��䴦��ͬ�������**��
     - `case 1`���� `rootCase` Ϊ 1 ʱ�����㲢���������ͬ��ʵ����
     - `case 2`���� `rootCase` Ϊ 2 ʱ�����㲢���һ��ʵ����
     - `case 3`���� `rootCase` Ϊ 3 ʱ��ʹ�� `std::complex<double>` ��������ʾ��������������ÿ�� `case` ��֧����ʱʹ�� `break` ��ֹ�������ִ����һ�� `case`��

������ͨ�� `switch` ���ʵ������һԪ���η��̸��Ĺ��ܡ� 