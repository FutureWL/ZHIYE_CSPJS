�����Ǽ���C++ �н���������С�Ƚϵİ�����

### �Ƚ���������
```cpp
#include <iostream>

int main() {
    int num1, num2;
    std::cout << "�������һ������: ";
    std::cin >> num1;
    std::cout << "������ڶ�������: ";
    std::cin >> num2;

    if (num1 > num2) {
        std::cout << num1 << " ���� " << num2 << std::endl;
    } else if (num1 < num2) {
        std::cout << num1 << " С�� " << num2 << std::endl;
    } else {
        std::cout << num1 << " ���� " << num2 << std::endl;
    }

    return 0;
}
```
����������У�
1. �������� `int` ���͵ı��� `num1` �� `num2`�����ڴ洢�û������������
2. ʹ�� `std::cout` ��ʾ�û�����������������ͨ�� `std::cin` ��ȡ�����ֵ��
3. ͨ�� `if - else if - else` ���� `num1` �� `num2` ���бȽϣ��������Ӧ�ıȽϽ����

### �Ƚ������������ҳ������
```cpp
#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "�������һ������: ";
    std::cin >> num1;
    std::cout << "������ڶ�������: ";
    std::cin >> num2;
    std::cout << "���������������: ";
    std::cin >> num3;

    int max = num1;
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }

    std::cout << "��������: " << max << std::endl;

    return 0;
}
```
�˰����Ĳ������£�
1. �������� `int` ���͵ı��� `num1`��`num2` �� `num3`�����ڴ洢�û������������
2. ��ʾ�û�������������������ȡ���롣
3. ���� `num1` �������������丳ֵ�� `max`��
4. ͨ������ `if` ���ֱ� `num2` �� `num3` �� `max` ���бȽϣ���� `num2` �� `num3` ��������� `max` ��ֵ��
5. �����������

### ʹ�ú����Ƚ���������
```cpp
#include <iostream>

// �Ƚ��������������ؽϴ�ֵ�ĺ���
int compareAndReturnMax(int a, int b) {
    return (a > b)? a : b;
}

int main() {
    int num1, num2;
    std::cout << "�������һ������: ";
    std::cin >> num1;
    std::cout << "������ڶ�������: ";
    std::cin >> num2;

    int max = compareAndReturnMax(num1, num2);
    std::cout << "�ϴ������: " << max << std::endl;

    return 0;
}
```
����������У�
1. ������һ������ `compareAndReturnMax`���ú����������� `int` ���͵Ĳ��� `a` �� `b`��ʹ����Ԫ������Ƚ� `a` �� `b`�������ؽϴ��ֵ��
2. �� `main` �����У������������� `num1` �� `num2`����ȡ�û����������������
3. ���� `compareAndReturnMax` ������ȡ�ϴ�ֵ��������洢�� `max` �����С�
4. ����ϴ������