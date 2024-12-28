以下是一个使用 `switch` 语句实现的简单计算器的C++ 案例。该计算器可以进行加、减、乘、除四种基本运算。

```cpp
#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "请输入第一个数字: ";
    std::cin >> num1;
    std::cout << "请输入运算符 (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "请输入第二个数字: ";
    std::cin >> num2;

    double result;
    switch (operation) {
    case '+':
        result = num1 + num2;
        std::cout << "结果是: " << result << std::endl;
        break;
    case '-':
        result = num1 - num2;
        std::cout << "结果是: " << result << std::endl;
        break;
    case '*':
        result = num1 * num2;
        std::cout << "结果是: " << result << std::endl;
        break;
    case '/':
        if (num2 == 0) {
            std::cout << "除数不能为零。" << std::endl;
        } else {
            result = num1 / num2;
            std::cout << "结果是: " << result << std::endl;
        }
        break;
    default:
        std::cout << "无效的运算符。" << std::endl;
        break;
    }

    return 0;
}
```

### 代码说明：
1. **变量声明**：
    - `num1` 和 `num2` 是 `double` 类型的变量，用于存储用户输入的两个操作数。
    - `operation` 是 `char` 类型的变量，用于存储用户输入的运算符。
    - `result` 是 `double` 类型的变量，用于存储运算结果。

2. **输入获取**：
    - 使用 `std::cout` 提示用户输入第一个数字、运算符和第二个数字，并通过 `std::cin` 获取用户输入的值。

3. **`switch` 语句**：
    - 根据 `operation` 的值进入不同的 `case` 分支执行相应的运算。
    - `case '+'`：执行加法运算，并输出结果。
    - `case '-'`：执行减法运算，并输出结果。
    - `case '*'`：执行乘法运算，并输出结果。
    - `case '/'`：首先检查除数是否为零，如果是则输出错误信息，否则执行除法运算并输出结果。
    - `default`：当用户输入的运算符不是 `+`、`-`、`*`、`/` 时，输出无效运算符的提示信息。

这样，通过 `switch` 语句实现了一个简单的计算器功能，能够根据用户输入的运算符和操作数进行基本的算术运算。