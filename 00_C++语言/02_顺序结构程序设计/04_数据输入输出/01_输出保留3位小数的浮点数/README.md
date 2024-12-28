在C++中，你可以使用`cout`和`<iomanip>`库来控制输出浮点数的小数位数。以下是一个输出保留3位小数浮点数的示例：

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double number = 123.456789;
    // 使用fixed表示以固定小数精度显示
    // setprecision(3) 设置小数位数为3
    std::cout << std::fixed << std::setprecision(3) << number << std::endl;

    return 0;
}
```

在上述代码中：
1. 引入了`<iostream>`库，用于输入输出操作。
2. 引入了`<iomanip>`库，该库提供了如`std::fixed`和`std::setprecision`等操作符，用于格式化输出。
3. 定义了一个`double`类型的变量`number`，并赋予初始值`123.456789`。
4. 使用`std::fixed`操作符，表示以固定小数精度显示浮点数，而不是科学计数法。
5. 使用`std::setprecision(3)`操作符，设置输出的小数位数为3位。
6. 最后通过`std::cout`输出保留3位小数的浮点数。

程序运行后，将输出`123.457`，其中最后一位数字7是经过四舍五入得到的。