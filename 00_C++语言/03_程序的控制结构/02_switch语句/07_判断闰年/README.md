1. **问题分析**：
   - 闰年的判断规则是：能被4整除但不能被100整除的年份为闰年，此外能被400整除的年份也是闰年。我们要使用 `switch` 语句实现判断一个年份是否为闰年的功能。
2. **代码实现**：
```cpp
#include <iostream>

int main() {
    int year;
    std::cout << "请输入一个年份: ";
    std::cin >> year;

    int isLeapYear = 0;
    if ((year % 4 == 0 && year % 100!= 0) || (year % 400 == 0)) {
        isLeapYear = 1;
    }

    switch (isLeapYear) {
    case 1:
        std::cout << year << " 是闰年。" << std::endl;
        break;
    default:
        std::cout << year << " 不是闰年。" << std::endl;
        break;
    }

    return 0;
}
```
3. **代码说明**：
   - **变量声明**：
     - 声明一个 `int` 类型变量 `year`，用于存储用户输入的年份。
     - 声明一个 `int` 类型变量 `isLeapYear`，用于标记该年份是否为闰年，初始化为 0（表示不是闰年）。
   - **输入获取**：
     - 使用 `std::cout` 提示用户输入一个年份，然后通过 `std::cin` 获取用户输入的值并存储到 `year` 中。
   - **判断是否为闰年**：
     - 通过 `if` 语句判断年份是否符合闰年的条件。如果 `year` 能被4整除且不能被100整除，或者 `year` 能被400整除，那么将 `isLeapYear` 设为 1（表示是闰年）。
   - **`switch` 语句输出结果**：
     - 使用 `switch` 语句根据 `isLeapYear` 的值进行输出。
     - `case 1` 分支对应 `isLeapYear` 为 1 的情况，即该年份是闰年，输出相应信息。
     - `default` 分支对应其他情况，也就是 `isLeapYear` 为 0，输出该年份不是闰年的信息。每个分支后面都使用 `break` 语句，以确保执行完相应分支后跳出 `switch` 语句。

这样就通过 `switch` 语句实现了判断一个年份是否为闰年的功能。 