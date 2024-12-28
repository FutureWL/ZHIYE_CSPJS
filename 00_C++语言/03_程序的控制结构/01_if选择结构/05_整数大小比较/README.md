以下是几个C++ 中进行整数大小比较的案例：

### 比较两个整数
```cpp
#include <iostream>

int main() {
    int num1, num2;
    std::cout << "请输入第一个整数: ";
    std::cin >> num1;
    std::cout << "请输入第二个整数: ";
    std::cin >> num2;

    if (num1 > num2) {
        std::cout << num1 << " 大于 " << num2 << std::endl;
    } else if (num1 < num2) {
        std::cout << num1 << " 小于 " << num2 << std::endl;
    } else {
        std::cout << num1 << " 等于 " << num2 << std::endl;
    }

    return 0;
}
```
在这个案例中：
1. 声明两个 `int` 类型的变量 `num1` 和 `num2`，用于存储用户输入的整数。
2. 使用 `std::cout` 提示用户输入两个整数，并通过 `std::cin` 获取输入的值。
3. 通过 `if - else if - else` 语句对 `num1` 和 `num2` 进行比较，并输出相应的比较结果。

### 比较三个整数并找出最大数
```cpp
#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "请输入第一个整数: ";
    std::cin >> num1;
    std::cout << "请输入第二个整数: ";
    std::cin >> num2;
    std::cout << "请输入第三个整数: ";
    std::cin >> num3;

    int max = num1;
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }

    std::cout << "最大的数是: " << max << std::endl;

    return 0;
}
```
此案例的步骤如下：
1. 声明三个 `int` 类型的变量 `num1`、`num2` 和 `num3`，用于存储用户输入的整数。
2. 提示用户输入三个整数，并获取输入。
3. 假设 `num1` 是最大的数，将其赋值给 `max`。
4. 通过两个 `if` 语句分别将 `num2` 和 `num3` 与 `max` 进行比较，如果 `num2` 或 `num3` 更大，则更新 `max` 的值。
5. 输出最大的数。

### 使用函数比较两个整数
```cpp
#include <iostream>

// 比较两个整数并返回较大值的函数
int compareAndReturnMax(int a, int b) {
    return (a > b)? a : b;
}

int main() {
    int num1, num2;
    std::cout << "请输入第一个整数: ";
    std::cin >> num1;
    std::cout << "请输入第二个整数: ";
    std::cin >> num2;

    int max = compareAndReturnMax(num1, num2);
    std::cout << "较大的数是: " << max << std::endl;

    return 0;
}
```
在这个案例中：
1. 定义了一个函数 `compareAndReturnMax`，该函数接受两个 `int` 类型的参数 `a` 和 `b`，使用三元运算符比较 `a` 和 `b`，并返回较大的值。
2. 在 `main` 函数中，声明两个变量 `num1` 和 `num2`，获取用户输入的两个整数。
3. 调用 `compareAndReturnMax` 函数获取较大值，并将其存储在 `max` 变量中。
4. 输出较大的数。