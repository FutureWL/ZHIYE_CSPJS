������һ��ʹ�� `switch` ���ʵ�ֵļ򵥼�������C++ �������ü��������Խ��мӡ������ˡ������ֻ������㡣

```cpp
#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "�������һ������: ";
    std::cin >> num1;
    std::cout << "����������� (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "������ڶ�������: ";
    std::cin >> num2;

    double result;
    switch (operation) {
    case '+':
        result = num1 + num2;
        std::cout << "�����: " << result << std::endl;
        break;
    case '-':
        result = num1 - num2;
        std::cout << "�����: " << result << std::endl;
        break;
    case '*':
        result = num1 * num2;
        std::cout << "�����: " << result << std::endl;
        break;
    case '/':
        if (num2 == 0) {
            std::cout << "��������Ϊ�㡣" << std::endl;
        } else {
            result = num1 / num2;
            std::cout << "�����: " << result << std::endl;
        }
        break;
    default:
        std::cout << "��Ч���������" << std::endl;
        break;
    }

    return 0;
}
```

### ����˵����
1. **��������**��
    - `num1` �� `num2` �� `double` ���͵ı��������ڴ洢�û������������������
    - `operation` �� `char` ���͵ı��������ڴ洢�û�������������
    - `result` �� `double` ���͵ı��������ڴ洢��������

2. **�����ȡ**��
    - ʹ�� `std::cout` ��ʾ�û������һ�����֡�������͵ڶ������֣���ͨ�� `std::cin` ��ȡ�û������ֵ��

3. **`switch` ���**��
    - ���� `operation` ��ֵ���벻ͬ�� `case` ��ִ֧����Ӧ�����㡣
    - `case '+'`��ִ�мӷ����㣬����������
    - `case '-'`��ִ�м������㣬����������
    - `case '*'`��ִ�г˷����㣬����������
    - `case '/'`�����ȼ������Ƿ�Ϊ�㣬����������������Ϣ������ִ�г������㲢��������
    - `default`�����û��������������� `+`��`-`��`*`��`/` ʱ�������Ч���������ʾ��Ϣ��

������ͨ�� `switch` ���ʵ����һ���򵥵ļ��������ܣ��ܹ������û������������Ͳ��������л������������㡣