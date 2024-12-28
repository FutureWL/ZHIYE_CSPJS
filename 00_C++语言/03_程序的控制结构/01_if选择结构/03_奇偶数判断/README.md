1. **�жϵ�������**
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "������һ������: ";
    std::cin >> num;

    if (num % 2 == 0) {
        std::cout << num << " ��ż��" << std::endl;
    } else {
        std::cout << num << " ������" << std::endl;
    }

    return 0;
}
```
�����������У�
    - ��������һ�����ͱ��� `num` ���ڴ洢�û������������
    - ʹ�� `std::cout` ��ʾ�û�����һ����������ͨ�� `std::cin` ��ȡ�û������ֵ���洢�� `num` �С�
    - ͨ��ȡģ���� `num % 2` �ж� `num` �Ƿ��ܱ�2�������������Ϊ0���������ż�������򣬸����������������жϽ�������Ӧ��Ϣ��

2. **�ж϶������**
```cpp
#include <iostream>

void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        std::cout << num << " ��ż��" << std::endl;
    } else {
        std::cout << num << " ������" << std::endl;
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; ++i) {
        checkEvenOdd(numbers[i]);
    }

    return 0;
}
```
�˴����У�
    - ������һ������ `checkEvenOdd`�������жϴ������������������ż�����������Ӧ��Ϣ��
    - �� `main` �����У�������һ���������� `numbers` ����ʼ����һЩֵ��ͨ����������Ĵ�С��ʹ�� `for` ѭ�����������е�ÿ��Ԫ�أ������� `checkEvenOdd` ������ÿ��Ԫ�ؽ�����ż���жϡ�

3. **�����û�����Ķ������**
```cpp
#include <iostream>

void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        std::cout << num << " ��ż��" << std::endl;
    } else {
        std::cout << num << " ������" << std::endl;
    }
}

int main() {
    int num;
    std::cout << "������һϵ���������� -1 ��������: " << std::endl;

    while (true) {
        std::cin >> num;
        if (num == -1) {
            break;
        }
        checkEvenOdd(num);
    }

    return 0;
}
```
������汾�У�
    - `checkEvenOdd` ������������һ��ʾ����ͬ��
    - �� `main` �����У�ʹ�� `while (true)` ����һ������ѭ������ʾ�û�����������ÿ�ζ�ȡһ�������󣬼���Ƿ�Ϊ `-1`�������������ѭ���������򣻷������ `checkEvenOdd` �����жϸ���������������ż���������������û�����������������жϡ� 