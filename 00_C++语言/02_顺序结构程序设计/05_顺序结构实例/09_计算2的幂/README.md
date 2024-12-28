��C++ �У�����2�����ж��ַ�ʽ�������Ǽ��������İ�����

### ʹ��ѭ��
```cpp
#include <iostream>

int main() {
    int exponent;
    std::cout << "������ָ��: ";
    std::cin >> exponent;

    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 2;
    }

    std::cout << "2 �� " << exponent << " ������: " << result << std::endl;
    return 0;
}
```
����������У�
1. ��������һ������ `exponent` ���ڴ洢�û������ָ����
2. ��ʾ�û�����ָ��ֵ����ͨ�� `std::cin` ��ȡ���롣
3. ��ʼ��������� `result` Ϊ1����Ϊ�κ�����0���ݶ�Ϊ1��
4. ʹ�� `for` ѭ����ѭ������Ϊָ����ֵ����ÿ��ѭ���У��� `result` ����2��
5. ��������������

### ʹ�� `<cmath>` ���е� `pow` ����
```cpp
#include <iostream>
#include <cmath>

int main() {
    int exponent;
    std::cout << "������ָ��: ";
    std::cin >> exponent;

    double result = std::pow(2, exponent);
    std::cout << "2 �� " << exponent << " ������: " << result << std::endl;

    return 0;
}
```
�˰����У�
1. ͬ���Ȼ�ȡ�û������ָ����
2. ���� `<cmath>` ���е� `std::pow` �������ú�������������������һ�������ǵ������ڶ���������ָ�������ؼ�������
3. �������������Ҫע����ǣ�`std::pow` �������ص��� `double` ���ͣ����ڴ���ϴ�ָ��ʱ���ܻ���ھ������⡣

### ʹ��λ���㣨�������ڷǸ�����ָ����
```cpp
#include <iostream>

int main() {
    int exponent;
    std::cout << "������Ǹ�ָ��: ";
    std::cin >> exponent;

    if (exponent < 0) {
        std::cout << "ָ������Ϊ�Ǹ�������" << std::endl;
        return 1;
    }

    long long result = 1LL << exponent;
    std::cout << "2 �� " << exponent << " ������: " << result << std::endl;

    return 0;
}
```
���
1. ��ȡ�û������ָ����������Ƿ�Ϊ�Ǹ�����������Ǹ��������������Ϣ����������
2. ʹ��λ���� `1LL << exponent` ������2���ݡ�`1LL` ��ʾ `long long` ���͵�1��`<<` ���������������1���� `exponent` λ���൱�ڳ���2�� `exponent` ���ݡ����ַ���Ч�ʽϸߣ����������ڴ����С�ķǸ�����ָ���� 