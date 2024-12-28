1. **使用`fmod`函数（标准库方式）**：
   - 在C++中，`<cmath>`头文件提供了`fmod`函数来计算两个浮点数相除的余数。该函数的原型为`double fmod(double x, double y)`，返回`x`除以`y`的浮点余数。
```cpp
#include <iostream>
#include <cmath>

int main() {
    double num1 = 7.5;
    double num2 = 2.5;
    double result = fmod(num1, num2);
    std::cout << num1 << " 除以 " << num2 << " 的余数是: " << result << std::endl;
    return 0;
}
```
   - 在上述代码中，定义了两个`double`类型的浮点数`num1`和`num2`，然后使用`fmod`函数计算`num1`除以`num2`的余数，并将结果输出。

2. **自定义实现浮点数求余（原理展示）**：
   - 浮点数求余的原理是通过反复减去除数，直到结果小于除数。以下是一个简单的自定义实现：
```cpp
#include <iostream>

double customFmod(double x, double y) {
    while (x >= y) {
        x -= y;
    }
    return x;
}

int main() {
    double num1 = 7.5;
    double num2 = 2.5;
    double result = customFmod(num1, num2);
    std::cout << num1 << " 除以 " << num2 << " 的余数是: " << result << std::endl;
    return 0;
}
```
   - 在这个自定义函数`customFmod`中，通过一个`while`循环不断从`x`中减去`y`，直到`x`小于`y`，此时的`x`就是余数。在`main`函数中调用这个自定义函数来计算并输出余数。

需要注意的是，由于浮点数在计算机中的存储方式，浮点数运算可能会存在精度问题。例如，对于一些看似简单的浮点数运算，结果可能与预期略有偏差。在实际应用中，如果对精度要求较高，可能需要额外的处理。 