1. **�жϵ����ַ���ASCIIֵ��ż��**
```cpp
#include <iostream>

int main() {
    char ch;
    std::cout << "������һ���ַ�: ";
    std::cin >> ch;
    int asciiValue = static_cast<int>(ch);
    if (asciiValue % 2 == 0) {
        std::cout << "�ַ� '" << ch << "' ��ASCIIֵ " << asciiValue << " ��ż����" << std::endl;
    } else {
        std::cout << "�ַ� '" << ch << "' ��ASCIIֵ " << asciiValue << " ��������" << std::endl;
    }
    return 0;
}
```
�����������У�
    - ��������һ���ַ����� `ch`�����ڴ洢�û�������ַ���
    - ʹ�� `std::cout` ��ʾ�û�����һ���ַ�����ͨ�� `std::cin` ��ȡ�û�������ַ���
    - ʹ�� `static_cast<int>(ch)` ���ַ� `ch` ת��Ϊ��Ӧ��ASCIIֵ���洢�� `asciiValue` �����С�
    - ͨ��ȡģ���� `asciiValue % 2` �ж� `asciiValue` �Ƿ��ܱ�2�����������жϽ�������Ӧ��Ϣ��

2. **�ж��ַ�����ÿ���ַ���ASCIIֵ��ż��**
```cpp
#include <iostream>
#include <string>

void checkASCIIParity(const std::string& str) {
    for (char ch : str) {
        int asciiValue = static_cast<int>(ch);
        if (asciiValue % 2 == 0) {
            std::cout << "�ַ� '" << ch << "' ��ASCIIֵ " << asciiValue << " ��ż����" << std::endl;
        } else {
            std::cout << "�ַ� '" << ch << "' ��ASCIIֵ " << asciiValue << " ��������" << std::endl;
        }
    }
}

int main() {
    std::string str;
    std::cout << "������һ���ַ���: ";
    std::getline(std::cin, str);
    checkASCIIParity(str);
    return 0;
}
```
����δ����У�
    - ������һ������ `checkASCIIParity`���ú�������һ�� `std::string` ���͵��ַ�����Ϊ������
    - ʹ�÷�Χ - for ѭ�������ַ����е�ÿ���ַ� `ch`������ת��ΪASCIIֵ���ж���ż�ԣ��������Ӧ��Ϣ��
    - �� `main` �����У�����һ�� `std::string` ���͵ı��� `str`��ʹ�� `std::getline` ������ȡ�û�������ַ�����Ȼ����� `checkASCIIParity` �������ַ����е�ÿ���ַ�����ASCIIֵ��ż���жϡ�

3. **����ASCIIֵ��ż�Խ����ַ�����**
```cpp
#include <iostream>
#include <string>
#include <vector>

std::vector<char> evenASCIIChars;
std::vector<char> oddASCIIChars;

void classifyByASCIIParity(const std::string& str) {
    for (char ch : str) {
        int asciiValue = static_cast<int>(ch);
        if (asciiValue % 2 == 0) {
            evenASCIIChars.push_back(ch);
        } else {
            oddASCIIChars.push_back(ch);
        }
    }
}

void printCharacterLists() {
    std::cout << "ASCIIֵΪż�����ַ�: ";
    for (char ch : evenASCIIChars) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    std::cout << "ASCIIֵΪ�������ַ�: ";
    for (char ch : oddASCIIChars) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string str;
    std::cout << "������һ���ַ���: ";
    std::getline(std::cin, str);
    classifyByASCIIParity(str);
    printCharacterLists();
    return 0;
}
```
�����ʾ���У�
    - ���������� `std::vector<char>` ���͵�ȫ�ֱ��� `evenASCIIChars` �� `oddASCIIChars`���ֱ����ڴ洢ASCIIֵΪż�����������ַ���
    - `classifyByASCIIParity` �������������ַ����������ַ���ASCIIֵ��ż�Խ���ֱ�洢����Ӧ�������С�
    - `printCharacterLists` ��������������������е��ַ���
    - �� `main` �����У���ȡ�û�������ַ��������� `classifyByASCIIParity` �������з��࣬Ȼ����� `printCharacterLists` ���������������