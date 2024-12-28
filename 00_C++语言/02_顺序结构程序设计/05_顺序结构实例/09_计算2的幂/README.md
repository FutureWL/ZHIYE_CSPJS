在C++ 中，计算2的幂有多种方式，以下是几个常见的案例：

### 使用循环
```cpp
#include <iostream>

int main() {
    int exponent;
    std::cout << "请输入指数: ";
    std::cin >> exponent;

    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 2;
    }

    std::cout << "2 的 " << exponent << " 次幂是: " << result << std::endl;
    return 0;
}
```
在这个案例中：
1. 首先声明一个变量 `exponent` 用于存储用户输入的指数。
2. 提示用户输入指数值，并通过 `std::cin` 获取输入。
3. 初始化结果变量 `result` 为1，因为任何数的0次幂都为1。
4. 使用 `for` 循环，循环次数为指数的值。在每次循环中，将 `result` 乘以2。
5. 最后输出计算结果。

### 使用 `<cmath>` 库中的 `pow` 函数
```cpp
#include <iostream>
#include <cmath>

int main() {
    int exponent;
    std::cout << "请输入指数: ";
    std::cin >> exponent;

    double result = std::pow(2, exponent);
    std::cout << "2 的 " << exponent << " 次幂是: " << result << std::endl;

    return 0;
}
```
此案例中：
1. 同样先获取用户输入的指数。
2. 调用 `<cmath>` 库中的 `std::pow` 函数，该函数接受两个参数，第一个参数是底数，第二个参数是指数，返回计算结果。
3. 输出计算结果。需要注意的是，`std::pow` 函数返回的是 `double` 类型，这在处理较大指数时可能会存在精度问题。

### 使用位运算（仅适用于非负整数指数）
```cpp
#include <iostream>

int main() {
    int exponent;
    std::cout << "请输入非负指数: ";
    std::cin >> exponent;

    if (exponent < 0) {
        std::cout << "指数必须为非负整数。" << std::endl;
        return 1;
    }

    long long result = 1LL << exponent;
    std::cout << "2 的 " << exponent << " 次幂是: " << result << std::endl;

    return 0;
}
```
这里：
1. 获取用户输入的指数，并检查是否为非负整数。如果是负数，输出错误信息并结束程序。
2. 使用位运算 `1LL << exponent` 来计算2的幂。`1LL` 表示 `long long` 类型的1，`<<` 是左移运算符，将1左移 `exponent` 位，相当于乘以2的 `exponent` 次幂。这种方法效率较高，尤其适用于处理较小的非负整数指数。 