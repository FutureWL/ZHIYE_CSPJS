�����Ǽ���C++ ����������ĳ���������

### 1. �������
```cpp
#include <iostream>

int main() {
    float floatNum = 3.14159f;
    double doubleNum = 3.141592653589793;

    std::cout << "Float: " << floatNum << std::endl;
    std::cout << "Double: " << doubleNum << std::endl;

    return 0;
}
```
����������У�������һ�� `float` ���ͺ�һ�� `double` ���͵ı�������ʹ�� `std::cout` ���������`float` ����ͨ���ṩԼ6 - 7λ��Ч���֣�`double` ����ͨ���ṩԼ15 - 17λ��Ч���֡�

### 2. ����С��λ�����
ͨ�� `<iomanip>` ���е� `std::fixed` �� `std::setprecision` �����������С��λ����
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.141592653589793;

    // ���ñ���2λС��
    std::cout << std::fixed << std::setprecision(2) << num << std::endl;

    // ���ñ���5λС��
    std::cout << std::fixed << std::setprecision(5) << num << std::endl;

    return 0;
}
```
`std::fixed` ��ʾ�Թ̶�С��������ʾ��`std::setprecision(n)` ��������С��λ��Ϊ `n`��

### 3. ��ѧ���������
ͬ������ʹ�� `<iomanip>` ���������Կ�ѧ�����������������
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double largeNum = 1234567890123.456;
    double smallNum = 0.000000123456;

    std::cout << std::scientific << largeNum << std::endl;
    std::cout << std::scientific << smallNum << std::endl;

    // ���ƿ�ѧ��������С��λ��
    std::cout << std::scientific << std::setprecision(3) << largeNum << std::endl;

    return 0;
}
```
`std::scientific` �����Կ�ѧ�����������`std::setprecision` Ҳ�������ڿ��ƿ�ѧ��������С�����ֵ�λ����

### 4. ʹ�ø�ʽ���ַ�����C++20 �����ϣ�
C++20 ����� `<format>` ���ṩ��һ���µĸ�ʽ�������ʽ��
```cpp
#include <iostream>
#include <format>

int main() {
    float num = 3.14159f;

    // ��ͨ���
    std::cout << std::format("Float: {}\n", num);

    // ����С��λ��
    std::cout << std::format("Float with 2 decimal places: {:.2f}\n", num);

    // ��ѧ���������
    std::cout << std::format("Float in scientific notation: {:.2e}\n", num);

    return 0;
}
```
�� `std::format` �У�`{}` ��ռλ����`{:.2f}` ��ʾ����2λС���ĸ�������`{:.2e}` ��ʾ����2λС���Ŀ�ѧ��������ʽ�� 