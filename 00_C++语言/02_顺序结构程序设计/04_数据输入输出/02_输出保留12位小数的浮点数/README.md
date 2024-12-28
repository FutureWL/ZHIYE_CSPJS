在C++ 中，要输出保留12位小数的浮点数，可以借助 `<iomanip > ` 头文件中的格式化操纵符。以下是一个示例代码：

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979323846;
    // 使用 fixed 以固定小数形式输出，setprecision 设置小数位数为12
    std::cout << std::fixed << std::setprecision(12) << num << std::endl;

    return 0;
}
```

在这个示例中：
1. 引入了 `<iostream > ` 头文件用于输入输出操作。
2. 引入了 `<iomanip > ` 头文件，它提供了诸如 `std::fixed` 和 `std::setprecision` 等格式化操纵符。
3. 定义了一个 `double` 类型的变量 `num` 并赋予一个高精度的初始值。
4. 使用 `std::fixed` 操纵符指定以固定小数格式输出，而不是科学计数法。
5. 使用 `std::setprecision(12)` 操纵符设置输出的小数位数为12位。
6. 最后通过 `std::cout` 输出保留12位小数的浮点数。

运行上述代码，将会输出 `3.141592653590`，你可以看到小数部分精确到了12位。

如果使用的是C++20及以上版本，还可以使用 `<format > ` 库来实现相同功能：

```cpp
#include <iostream>
#include <format>

int main() {
    double num = 3.14159265358979323846;
    std::cout << std::format("{:.12f}", num);
    return 0;
}
```

在这个代码中，`std::format` 函数接受一个格式化字符串 `"{:.12f}"`，其中 `.12` 表示保留12位小数，`f` 表示以普通小数形式输出。`std::format` 函数会根据格式化字符串将 `num` 格式化为指定的形式并返回一个格式化后的字符串，最后通过 `std::cout` 输出。 