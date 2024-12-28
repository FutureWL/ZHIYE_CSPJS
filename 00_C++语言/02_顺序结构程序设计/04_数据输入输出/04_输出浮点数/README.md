以下是几个C++ 输出浮点数的常见案例：

### 1. 基本输出
```cpp
#include <iostream>

int main() {
    float floatNum = 3.14159f;
    double doubleNum = 3.141592653589793;

    std::cout << "Float: " << floatNum << std::endl;
    std::cout << "Double: " << doubleNum << std::endl;

    return 0;
}
```
在这个案例中，定义了一个 `float` 类型和一个 `double` 类型的变量，并使用 `std::cout` 进行输出。`float` 类型通常提供约6 - 7位有效数字，`double` 类型通常提供约15 - 17位有效数字。

### 2. 控制小数位数输出
通过 `<iomanip>` 库中的 `std::fixed` 和 `std::setprecision` 来控制输出的小数位数。
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.141592653589793;

    // 设置保留2位小数
    std::cout << std::fixed << std::setprecision(2) << num << std::endl;

    // 设置保留5位小数
    std::cout << std::fixed << std::setprecision(5) << num << std::endl;

    return 0;
}
```
`std::fixed` 表示以固定小数精度显示，`std::setprecision(n)` 用于设置小数位数为 `n`。

### 3. 科学计数法输出
同样可以使用 `<iomanip>` 库来控制以科学计数法输出浮点数。
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double largeNum = 1234567890123.456;
    double smallNum = 0.000000123456;

    std::cout << std::scientific << largeNum << std::endl;
    std::cout << std::scientific << smallNum << std::endl;

    // 控制科学计数法的小数位数
    std::cout << std::scientific << std::setprecision(3) << largeNum << std::endl;

    return 0;
}
```
`std::scientific` 用于以科学计数法输出，`std::setprecision` 也可以用于控制科学计数法中小数部分的位数。

### 4. 使用格式化字符串（C++20 及以上）
C++20 引入的 `<format>` 库提供了一种新的格式化输出方式。
```cpp
#include <iostream>
#include <format>

int main() {
    float num = 3.14159f;

    // 普通输出
    std::cout << std::format("Float: {}\n", num);

    // 控制小数位数
    std::cout << std::format("Float with 2 decimal places: {:.2f}\n", num);

    // 科学计数法输出
    std::cout << std::format("Float in scientific notation: {:.2e}\n", num);

    return 0;
}
```
在 `std::format` 中，`{}` 是占位符，`{:.2f}` 表示保留2位小数的浮点数，`{:.2e}` 表示保留2位小数的科学计数法形式。 