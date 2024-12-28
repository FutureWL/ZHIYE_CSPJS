1. **�����жϰ���**
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "������һ������: ";
    std::cin >> num;

    if (num % 3 == 0 && num % 5 == 0) {
        std::cout << num << " ��ͬʱ�� 3 �� 5 ������" << std::endl;
    } else {
        std::cout << num << " ����ͬʱ�� 3 �� 5 ������" << std::endl;
    }

    return 0;
}
```
�����������У�
    - ��������һ�����ͱ��� `num` ���ڴ洢�û������������
    - ʹ�� `std::cout` ��ʾ�û�����һ����������ͨ�� `std::cin` ��ȡ�û������ֵ���洢�� `num` �С�
    - ͨ��ȡģ���� `num % 3 == 0 && num % 5 == 0` �ж� `num` �Ƿ���ͬʱ��3��5��������� `num` ����3������Ϊ0���ҳ���5������ҲΪ0��˵����ͬʱ��3��5�����������Ӧ��Ϣ�������������ͬʱ��3��5��������Ϣ��

2. **ʹ�ú�����װ�ж��߼�**
```cpp
#include <iostream>

bool isDivisibleBy3And5(int num) {
    return num % 3 == 0 && num % 5 == 0;
}

int main() {
    int num;
    std::cout << "������һ������: ";
    std::cin >> num;

    if (isDivisibleBy3And5(num)) {
        std::cout << num << " ��ͬʱ�� 3 �� 5 ������" << std::endl;
    } else {
        std::cout << num << " ����ͬʱ�� 3 �� 5 ������" << std::endl;
    }

    return 0;
}
```
�˴����У�
    - ������һ����Ϊ `isDivisibleBy3And5` �ĺ������ú�������һ���������� `num`��ͨ�� `return num % 3 == 0 && num % 5 == 0` �ж� `num` �Ƿ���ͬʱ��3��5���������� `true` �� `false`��
    - �� `main` �����У���ȡ�û���������� `num`��Ȼ����� `isDivisibleBy3And5` ���������жϣ������ݷ��ؽ�������Ӧ��Ϣ�����ַ�ʽ���ж��߼���װ�ں����У�ʹ����ṹ�����������ڸ��á�

3. **�����������ж�**
```cpp
#include <iostream>

bool isDivisibleBy3And5(int num) {
    return num % 3 == 0 && num % 5 == 0;
}

int main() {
    int numbers[] = {10, 15, 20, 30};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; ++i) {
        if (isDivisibleBy3And5(numbers[i])) {
            std::cout << numbers[i] << " ��ͬʱ�� 3 �� 5 ������" << std::endl;
        } else {
            std::cout << numbers[i] << " ����ͬʱ�� 3 �� 5 ������" << std::endl;
        }
    }

    return 0;
}
```
������汾�У�
    - ͬ�������� `isDivisibleBy3And5` ���������ж�һ�����Ƿ���ͬʱ��3��5������
    - �� `main` �����У�������һ���������� `numbers` ����ʼ����һЩֵ��ͨ����������Ĵ�С��ʹ�� `for` ѭ�����������е�ÿ��Ԫ�أ����� `isDivisibleBy3And5` ������ÿ��Ԫ�ؽ����жϣ��������Ӧ��Ϣ���������ԶԶ��������ͬʱ��3��5�������жϡ� 