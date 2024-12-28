1. **问题描述**：
   - 假设有如下分段函数：
   - \( y = \begin{cases}
     -1, & x < 0 \\
     0, & x = 0 \\
     1, & x > 0
   \end{cases} \)
   - 编写一个C++ 程序，使用 `switch` 语句来实现这个分段函数，根据用户输入的 `x` 值计算并输出对应的 `y` 值。
2. **代码实现**：
```cpp
#include <iostream>

int main() {
    int x;
    std::cout << "请输入一个整数 x: ";
    std::cin >> x;

    int condition = 0;
    if (x < 0) {
        condition = -1;
    } else if (x > 0) {
        condition = 1;
    }

    int y;
    switch (condition) {
    case -1:
        y = -1;
        break;
    case 0:
        y = 0;
        break;
    case 1:
        y = 1;
        break;
    }

    std::cout << "当 x = " << x << " 时，y = " << y << std::endl;

    return 0;
}
```
3. **代码说明**：
   - **变量声明**：
     - 声明一个 `int` 类型变量 `x`，用于存储用户输入的值。
     - 声明一个 `int` 类型变量 `condition`，用于根据 `x` 的值确定进入 `switch` 语句的哪个分支，初始化为 0。
     - 声明一个 `int` 类型变量 `y`，用于存储分段函数的计算结果。
   - **输入获取**：使用 `std::cout` 提示用户输入一个整数 `x`，并通过 `std::cin` 获取用户输入的值。
   - **条件判断**：
     - 通过 `if - else if` 语句判断 `x` 的值，若 `x` 小于 0，将 `condition` 设为 -1；若 `x` 大于 0，将 `condition` 设为 1；若 `x` 等于 0，`condition` 保持为 0。
   - **`switch` 语句**：
     - 根据 `condition` 的值进入不同的 `case` 分支。
     - `case -1` 分支对应 `x < 0` 的情况，将 `y` 设为 -1 并使用 `break` 跳出 `switch` 语句。
     - `case 0` 分支对应 `x = 0` 的情况，将 `y` 设为 0 并使用 `break` 跳出 `switch` 语句。
     - `case 1` 分支对应 `x > 0` 的情况，将 `y` 设为 1 并使用 `break` 跳出 `switch` 语句。
   - **结果输出**：最后，使用 `std::cout` 输出当 `x` 为用户输入值时，对应的 `y` 值。

这个示例展示了如何使用 `switch` 语句实现一个简单的分段函数。如果分段函数的条件更为复杂，可能需要对代码进行相应调整，例如使用更复杂的条件判断来确定 `switch` 的 `case` 分支。 