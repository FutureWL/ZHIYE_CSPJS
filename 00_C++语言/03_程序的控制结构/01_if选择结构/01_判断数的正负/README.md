1. **�����ж�**
   - ������һ���򵥵�C++���������ж�һ�����������������������㡣
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "������һ������: ";
    std::cin >> num;
    if (num > 0) {
        std::cout << num << " ��������" << std::endl;
    } else if (num < 0) {
        std::cout << num << " �Ǹ�����" << std::endl;
    } else {
        std::cout << num << " ���㡣" << std::endl;
    }
    return 0;
}
```
   - �����������У�
     - ��������һ�����ͱ��� `num` ���ڴ洢�û������������
     - Ȼ��ʹ�� `std::cout` ��ʾ�û�����һ����������ͨ�� `std::cin` ��ȡ�û������ֵ���洢�� `num` �С�
     - ����ʹ�� `if - else if - else` �������жϡ���� `num` ���� 0���������������������� `num` С�� 0������������Ǹ�������� `num` ���� 0��������������㡣

2. **��������**
   - �ó�����Դ��������������жϡ�
```cpp
#include <iostream>

int main() {
    double num;
    std::cout << "������һ��������: ";
    std::cin >> num;
    if (num > 0) {
        std::cout << num << " ��������" << std::endl;
    } else if (num < 0) {
        std::cout << num << " �Ǹ�����" << std::endl;
    } else {
        std::cout << num << " ���㡣" << std::endl;
    }
    return 0;
}
```
   - ���ｫ�������͸�Ϊ `double`���Դ����������룬�ж��߼��봦������ʱ��ͬ��

3. **ʹ�ú�����װ�ж��߼�**
   - ���Խ��ж��߼���װ��һ�������У�ʹ����ṹ�����������ڸ��á�
```cpp
#include <iostream>

void checkSign(double num) {
    if (num > 0) {
        std::cout << num << " ��������" << std::endl;
    } else if (num < 0) {
        std::cout << num << " �Ǹ�����" << std::endl;
    } else {
        std::cout << num << " ���㡣" << std::endl;
    }
}

int main() {
    double num;
    std::cout << "������һ����: ";
    std::cin >> num;
    checkSign(num);
    return 0;
}
```
   - ����������У�������һ����Ϊ `checkSign` �ĺ������ú�������һ�� `double` ���͵Ĳ��� `num`�����ں����ڲ����������жϺ�������� `main` �����У���ȡ�û������������� `checkSign` ���������жϡ� 