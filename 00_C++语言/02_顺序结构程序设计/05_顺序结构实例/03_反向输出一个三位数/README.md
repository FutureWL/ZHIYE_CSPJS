������һ����C++ �з������һ����λ���İ�����

```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "������һ����λ��: ";
    std::cin >> number;

    if (number >= 100 && number <= 999) {
        int units = number % 10;
        int tens = (number / 10) % 10;
        int hundreds = number / 100;

        int reversedNumber = units * 100 + tens * 10 + hundreds;
        std::cout << "������������: " << reversedNumber << std::endl;
    } else {
        std::cout << "����Ĳ���һ����λ����" << std::endl;
    }

    return 0;
}
```

�����������У�
1. ��������һ������ `number` ���ڴ洢�û���������֡�
2. ��ʾ�û�����һ����λ�������������ֵ�洢�� `number` �С�
3. ʹ��ȡ��ͳ�����������������λ���ĸ�λ��ʮλ�Ͱ�λ��
    - `number % 10` ���ڻ�ȡ��λ���֡�
    - `(number / 10) % 10` �Ƚ����ֳ���10ȥ����λ���ٶ�10ȡ��õ�ʮλ���֡�
    - `number / 100` ֱ�ӵõ���λ���֡�
4. Ȼ�����������Щ���֣��õ����������� `reversedNumber`��
5. ���������������֡�����û�����Ĳ�����λ�����������ʾ��Ϣ��