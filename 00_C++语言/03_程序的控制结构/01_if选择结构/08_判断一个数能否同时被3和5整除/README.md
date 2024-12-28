1. **基本判断案例**
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "请输入一个整数: ";
    std::cin >> num;

    if (num % 3 == 0 && num % 5 == 0) {
        std::cout << num << " 能同时被 3 和 5 整除。" << std::endl;
    } else {
        std::cout << num << " 不能同时被 3 和 5 整除。" << std::endl;
    }

    return 0;
}
```
在上述代码中：
    - 首先声明一个整型变量 `num` 用于存储用户输入的整数。
    - 使用 `std::cout` 提示用户输入一个整数，并通过 `std::cin` 获取用户输入的值并存储到 `num` 中。
    - 通过取模运算 `num % 3 == 0 && num % 5 == 0` 判断 `num` 是否能同时被3和5整除。如果 `num` 除以3的余数为0并且除以5的余数也为0，说明能同时被3和5整除，输出相应信息；否则，输出不能同时被3和5整除的信息。

2. **使用函数封装判断逻辑**
```cpp
#include <iostream>

bool isDivisibleBy3And5(int num) {
    return num % 3 == 0 && num % 5 == 0;
}

int main() {
    int num;
    std::cout << "请输入一个整数: ";
    std::cin >> num;

    if (isDivisibleBy3And5(num)) {
        std::cout << num << " 能同时被 3 和 5 整除。" << std::endl;
    } else {
        std::cout << num << " 不能同时被 3 和 5 整除。" << std::endl;
    }

    return 0;
}
```
此代码中：
    - 定义了一个名为 `isDivisibleBy3And5` 的函数，该函数接受一个整数参数 `num`，通过 `return num % 3 == 0 && num % 5 == 0` 判断 `num` 是否能同时被3和5整除，返回 `true` 或 `false`。
    - 在 `main` 函数中，获取用户输入的整数 `num`，然后调用 `isDivisibleBy3And5` 函数进行判断，并根据返回结果输出相应信息。这种方式将判断逻辑封装在函数中，使代码结构更清晰，便于复用。

3. **处理多个数的判断**
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
            std::cout << numbers[i] << " 能同时被 3 和 5 整除。" << std::endl;
        } else {
            std::cout << numbers[i] << " 不能同时被 3 和 5 整除。" << std::endl;
        }
    }

    return 0;
}
```
在这个版本中：
    - 同样定义了 `isDivisibleBy3And5` 函数用于判断一个数是否能同时被3和5整除。
    - 在 `main` 函数中，定义了一个整数数组 `numbers` 并初始化了一些值。通过计算数组的大小，使用 `for` 循环遍历数组中的每个元素，调用 `isDivisibleBy3And5` 函数对每个元素进行判断，并输出相应信息。这样可以对多个数进行同时被3和5整除的判断。 