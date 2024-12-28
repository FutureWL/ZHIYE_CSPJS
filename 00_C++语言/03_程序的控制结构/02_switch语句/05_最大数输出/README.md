1. **需求分析**：
   - 要求编写一个C++ 程序，通过 `switch` 语句找出三个整数中的最大值并输出。
2. **代码实现**：
```cpp
#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "请输入三个整数，以空格分隔: ";
    std::cin >> num1 >> num2 >> num3;

    int maxIndex = 0;
    if (num2 > num1) {
        if (num2 > num3) {
            maxIndex = 2;
        } else {
            maxIndex = 3;
        }
    } else {
        if (num1 > num3) {
            maxIndex = 1;
        } else {
            maxIndex = 3;
        }
    }

    int maxNumber;
    switch (maxIndex) {
    case 1:
        maxNumber = num1;
        break;
    case 2:
        maxNumber = num2;
        break;
    case 3:
        maxNumber = num3;
        break;
    }

    std::cout << "最大的数是: " << maxNumber << std::endl;

    return 0;
}
```
3. **代码说明**：
   - **变量声明**：
     - 声明三个 `int` 类型变量 `num1`、`num2` 和 `num3`，用于存储用户输入的三个整数。
     - 声明一个 `int` 类型变量 `maxIndex`，用于标记最大数所在的位置，初始化为 0。这里假设 `num1` 为最大数的索引为 1，`num2` 为最大数的索引为 2，`num3` 为最大数的索引为 3。
     - 声明一个 `int` 类型变量 `maxNumber`，用于存储找到的最大数。
   - **输入获取**：
     - 使用 `std::cout` 提示用户输入三个整数，并且使用 `std::cin` 从输入流中读取这三个整数。
   - **确定最大数的索引**：
     - 通过嵌套的 `if - else` 语句来比较 `num1`、`num2` 和 `num3` 的大小，确定最大数所在的位置，并将其索引赋值给 `maxIndex`。
   - **`switch` 语句获取最大数**：
     - 根据 `maxIndex` 的值进入不同的 `case` 分支。
     - `case 1` 分支，当 `maxIndex` 为 1 时，将 `num1` 赋值给 `maxNumber`。
     - `case 2` 分支，当 `maxIndex` 为 2 时，将 `num2` 赋值给 `maxNumber`。
     - `case 3` 分支，当 `maxIndex` 为 3 时，将 `num3` 赋值给 `maxNumber`。
   - **结果输出**：
     - 使用 `std::cout` 输出找到的最大数。

虽然使用 `switch` 语句实现这个功能相对复杂，通常可以直接使用简单的比较语句来完成，但此代码展示了如何在这种场景下运用 `switch` 语句。 