以下是一个在C++ 中反向输出一个三位数的案例：

```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "请输入一个三位数: ";
    std::cin >> number;

    if (number >= 100 && number <= 999) {
        int units = number % 10;
        int tens = (number / 10) % 10;
        int hundreds = number / 100;

        int reversedNumber = units * 100 + tens * 10 + hundreds;
        std::cout << "反向后的数字是: " << reversedNumber << std::endl;
    } else {
        std::cout << "输入的不是一个三位数。" << std::endl;
    }

    return 0;
}
```

在上述代码中：
1. 首先声明一个变量 `number` 用于存储用户输入的数字。
2. 提示用户输入一个三位数，并将输入的值存储到 `number` 中。
3. 使用取余和除法操作分离出这个三位数的个位、十位和百位。
    - `number % 10` 用于获取个位数字。
    - `(number / 10) % 10` 先将数字除以10去掉个位，再对10取余得到十位数字。
    - `number / 100` 直接得到百位数字。
4. 然后重新组合这些数字，得到反向后的数字 `reversedNumber`。
5. 最后输出反向后的数字。如果用户输入的不是三位数，则输出提示信息。