1. **判断单个整数**
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "请输入一个整数: ";
    std::cin >> num;

    if (num % 2 == 0) {
        std::cout << num << " 是偶数" << std::endl;
    } else {
        std::cout << num << " 是奇数" << std::endl;
    }

    return 0;
}
```
在上述代码中：
    - 首先声明一个整型变量 `num` 用于存储用户输入的整数。
    - 使用 `std::cout` 提示用户输入一个整数，并通过 `std::cin` 获取用户输入的值并存储到 `num` 中。
    - 通过取模运算 `num % 2` 判断 `num` 是否能被2整除。如果余数为0，则该数是偶数；否则，该数是奇数。根据判断结果输出相应信息。

2. **判断多个整数**
```cpp
#include <iostream>

void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        std::cout << num << " 是偶数" << std::endl;
    } else {
        std::cout << num << " 是奇数" << std::endl;
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
此代码中：
    - 定义了一个函数 `checkEvenOdd`，用于判断传入的整数是奇数还是偶数，并输出相应信息。
    - 在 `main` 函数中，定义了一个整数数组 `numbers` 并初始化了一些值。通过计算数组的大小，使用 `for` 循环遍历数组中的每个元素，并调用 `checkEvenOdd` 函数对每个元素进行奇偶数判断。

3. **处理用户输入的多个整数**
```cpp
#include <iostream>

void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        std::cout << num << " 是偶数" << std::endl;
    } else {
        std::cout << num << " 是奇数" << std::endl;
    }
}

int main() {
    int num;
    std::cout << "请输入一系列整数，以 -1 结束输入: " << std::endl;

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
在这个版本中：
    - `checkEvenOdd` 函数功能与上一个示例相同。
    - 在 `main` 函数中，使用 `while (true)` 构建一个无限循环，提示用户输入整数。每次读取一个整数后，检查是否为 `-1`，如果是则跳出循环结束程序；否则调用 `checkEvenOdd` 函数判断该整数是奇数还是偶数。这样可以让用户输入多个整数并逐个判断。 