1. **问题描述**：晶晶赴约会，假设晶晶只有在周一晚上、周三晚上、周五晚上才有时间赴约。通过用户输入约会时间，使用 `switch` 语句判断晶晶是否能赴约。
2. **代码实现**：
```cpp
#include <iostream>
#include <string>

int main() {
    std::string time;
    std::cout << "请输入约会时间（格式：周X晚上）: ";
    std::cin >> time;

    int dayIndex = -1;
    if (time == "周一晚上") {
        dayIndex = 1;
    } else if (time == "周二晚上") {
        dayIndex = 2;
    } else if (time == "周三晚上") {
        dayIndex = 3;
    } else if (time == "周四晚上") {
        dayIndex = 4;
    } else if (time == "周五晚上") {
        dayIndex = 5;
    } else if (time == "周六晚上") {
        dayIndex = 6;
    } else if (time == "周日晚上") {
        dayIndex = 7;
    }

    switch (dayIndex) {
    case 1:
    case 3:
    case 5:
        std::cout << "晶晶可以赴约。" << std::endl;
        break;
    default:
        std::cout << "晶晶无法赴约。" << std::endl;
        break;
    }

    return 0;
}
```
3. **代码说明**：
    - **变量声明**：声明一个 `std::string` 类型的变量 `time` 用于存储用户输入的约会时间。还声明了一个 `int` 类型变量 `dayIndex` 并初始化为 -1，用于标记输入时间对应的索引。
    - **输入获取**：通过 `std::cout` 提示用户输入约会时间，并使用 `std::cin` 获取用户输入的值存储到 `time` 中。
    - **时间索引处理**：通过一系列 `if - else if` 语句判断输入的时间字符串，将对应的时间索引赋值给 `dayIndex`。如果输入的时间格式不正确，`dayIndex` 仍为 -1。
    - **`switch` 语句判断**：使用 `switch` 语句根据 `dayIndex` 的值进行判断。如果 `dayIndex` 为 1（周一晚上）、3（周三晚上）或 5（周五晚上），则输出晶晶可以赴约；否则，输出晶晶无法赴约。每个 `case` 分支后使用 `break` 语句防止程序继续执行下一个 `case`。

这样就通过 `switch` 语句实现了根据输入时间判断晶晶是否能赴约的功能。你可以根据实际需求进一步优化代码，例如增加对输入格式的严格校验等。 