��C++ �У����㲢���һ�����ľ���ֵ�ж��ַ���������Ϊ��չʾ��������������

### 1. �����������
```cpp
#include <iostream>
#include <cmath>

int main() {
    int num = -10;
    int absValue = std::abs(num);
    std::cout << "���� " << num << " �ľ���ֵ��: " << absValue << std::endl;
    return 0;
}
```
�����������У�
 - ���ȶ�����һ�� `int` ���ͱ��� `num` ����ʼ��Ϊ `-10`��
 - Ȼ��ʹ�� `<cmath>` ���е� `std::abs` ���������� `num` �ľ���ֵ���ú��������������ͻ᷵�ض�Ӧ���޷���������
 - ���ͨ�� `std::cout` ��������

### 2. ��Ը���������
```cpp
#include <iostream>
#include <cmath>

int main() {
    double num = -3.14;
    double absValue = std::fabs(num);
    std::cout << "������ " << num << " �ľ���ֵ��: " << absValue << std::endl;
    return 0;
}
```
���
 - ������ `double` ���ͱ��� `num` ����ʼ��Ϊ `-3.14`��
 - ���ڸ�������ʹ�� `<cmath>` ���е� `std::fabs` ���������������ֵ�����������������ͬ���͵ĸ�������
 - �������������ľ���ֵ��

### 3. �Զ������ֵ����
```cpp
#include <iostream>

// �Զ��庯��������������ֵ
int myAbs(int num) {
    return num < 0? -num : num;
}

// �Զ��庯�����㸡��������ֵ
double myAbs(double num) {
    return num < 0? -num : num;
}

int main() {
    int intNum = -5;
    double doubleNum = -2.718;

    int intAbsValue = myAbs(intNum);
    double doubleAbsValue = myAbs(doubleNum);

    std::cout << "�Զ��庯�������� " << intNum << " �ľ���ֵ��: " << intAbsValue << std::endl;
    std::cout << "�Զ��庯���������� " << doubleNum << " �ľ���ֵ��: " << doubleAbsValue << std::endl;

    return 0;
}
```
�����ʾ���У�
 - �������������ص� `myAbs` ������һ�����ڼ��� `int` ���͵ľ���ֵ����һ�����ڼ��� `double` ���͵ľ���ֵ��
 - �� `myAbs` �����ڲ���ʹ����Ԫ������ж������Ƿ�Ϊ������������򷵻����෴�������򷵻����ֱ���
 - �� `main` �����У��ֱ����� `int` ���ͺ� `double` ���͵ı������������Զ���� `myAbs` �����������ǵľ���ֵ������� 