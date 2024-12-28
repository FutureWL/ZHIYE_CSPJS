1. **ʹ�û��������ж�**
```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "������һ������: ";
    std::cin >> number;

    if (number >= 10 && number <= 99) {
        std::cout << number << " ����λ����" << std::endl;
    } else {
        std::cout << number << " ������λ����" << std::endl;
    }

    return 0;
}
```
�����������У�
    - ��������һ�����ͱ��� `number` ���ڴ洢�û������������
    - ʹ�� `std::cout` ��ʾ�û�����һ����������ͨ�� `std::cin` ��ȡ�û������ֵ���洢�� `number` �С�
    - ͨ�������ж� `number >= 10 && number <= 99`������������������˵����������λ���������Ӧ��ʾ�������������������λ������ʾ��

2. **ʹ�ú�����װ�ж��߼�**
```cpp
#include <iostream>

bool isTwoDigitNumber(int num) {
    return num >= 10 && num <= 99;
}

int main() {
    int number;
    std::cout << "������һ������: ";
    std::cin >> number;

    if (isTwoDigitNumber(number)) {
        std::cout << number << " ����λ����" << std::endl;
    } else {
        std::cout << number << " ������λ����" << std::endl;
    }

    return 0;
}
```
�˴����У�
    - ������һ����Ϊ `isTwoDigitNumber` �ĺ������ú�������һ���������� `num`����ͨ�� `return num >= 10 && num <= 99` �жϸ����Ƿ�Ϊ��λ�������� `true` �� `false`��
    - �� `main` �����У���ȡ�û���������� `number`��Ȼ����� `isTwoDigitNumber` ���������жϣ������ݷ��ؽ�������Ӧ��Ϣ�����ַ�ʽ���ж��߼���װ�ں����У�ʹ����ṹ�����������ڸ��á�

3. **���������쳣��������������룩**
```cpp
#include <iostream>
#include <limits>

bool isTwoDigitNumber(int num) {
    return num >= 10 && num <= 99;
}

int main() {
    int number;
    while (true) {
        std::cout << "������һ������: ";
        if (!(std::cin >> number)) {
            std::cout << "������Ч��������һ��������" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    if (isTwoDigitNumber(number)) {
        std::cout << number << " ����λ����" << std::endl;
    } else {
        std::cout << number << " ������λ����" << std::endl;
    }

    return 0;
}
```
������汾�У�
    - ͬ�������� `isTwoDigitNumber` ���������ж��Ƿ�Ϊ��λ����
    - �� `main` �����У�ʹ�� `while (true)` ����һ��ѭ�������û����벻������ʱ��`std::cin >> number` ��ʧ�ܣ���ʱ���������ʾ������ `std::cin.clear()` �������״̬��`std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')` �������뻺�����еĴ������룬Ȼ�����ѭ����ʾ�û����롣ֻ�е�����Ϊ����ʱ���Ż�����ѭ�������Ƿ�Ϊ��λ�����жϣ��������Ӧ���������������ǿ����Ľ�׳�ԣ������û����ܵĴ������롣 