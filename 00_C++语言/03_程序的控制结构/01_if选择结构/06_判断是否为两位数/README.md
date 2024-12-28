1. **使用基本条件判断**
```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "请输入一个整数: ";
    std::cin >> number;

    if (number >= 10 && number <= 99) {
        std::cout << number << " 是两位数。" << std::endl;
    } else {
        std::cout << number << " 不是两位数。" << std::endl;
    }

    return 0;
}
```
在上述代码中：
    - 首先声明一个整型变量 `number` 用于存储用户输入的整数。
    - 使用 `std::cout` 提示用户输入一个整数，并通过 `std::cin` 获取用户输入的值并存储到 `number` 中。
    - 通过条件判断 `number >= 10 && number <= 99`，如果满足这个条件，说明该数是两位数，输出相应提示；否则，输出该数不是两位数的提示。

2. **使用函数封装判断逻辑**
```cpp
#include <iostream>

bool isTwoDigitNumber(int num) {
    return num >= 10 && num <= 99;
}

int main() {
    int number;
    std::cout << "请输入一个整数: ";
    std::cin >> number;

    if (isTwoDigitNumber(number)) {
        std::cout << number << " 是两位数。" << std::endl;
    } else {
        std::cout << number << " 不是两位数。" << std::endl;
    }

    return 0;
}
```
此代码中：
    - 定义了一个名为 `isTwoDigitNumber` 的函数，该函数接受一个整数参数 `num`，并通过 `return num >= 10 && num <= 99` 判断该数是否为两位数，返回 `true` 或 `false`。
    - 在 `main` 函数中，获取用户输入的整数 `number`，然后调用 `isTwoDigitNumber` 函数进行判断，并根据返回结果输出相应信息。这种方式将判断逻辑封装在函数中，使代码结构更清晰，便于复用。

3. **处理输入异常情况（非整数输入）**
```cpp
#include <iostream>
#include <limits>

bool isTwoDigitNumber(int num) {
    return num >= 10 && num <= 99;
}

int main() {
    int number;
    while (true) {
        std::cout << "请输入一个整数: ";
        if (!(std::cin >> number)) {
            std::cout << "输入无效，请输入一个整数。" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    if (isTwoDigitNumber(number)) {
        std::cout << number << " 是两位数。" << std::endl;
    } else {
        std::cout << number << " 不是两位数。" << std::endl;
    }

    return 0;
}
```
在这个版本中：
    - 同样定义了 `isTwoDigitNumber` 函数用于判断是否为两位数。
    - 在 `main` 函数中，使用 `while (true)` 构建一个循环，当用户输入不是整数时，`std::cin >> number` 会失败，此时输出错误提示，调用 `std::cin.clear()` 清除错误状态，`std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')` 忽略输入缓冲区中的错误输入，然后继续循环提示用户输入。只有当输入为整数时，才会跳出循环进行是否为两位数的判断，并输出相应结果。这样可以增强程序的健壮性，处理用户可能的错误输入。 