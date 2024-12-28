在C++ 中，计算并输出一个数的绝对值有多种方法，以下为你展示几个常见案例：

### 1. 针对整数类型
```cpp
#include <iostream>
#include <cmath>

int main() {
    int num = -10;
    int absValue = std::abs(num);
    std::cout << "整数 " << num << " 的绝对值是: " << absValue << std::endl;
    return 0;
}
```
在上述代码中：
 - 首先定义了一个 `int` 类型变量 `num` 并初始化为 `-10`。
 - 然后使用 `<cmath>` 库中的 `std::abs` 函数来计算 `num` 的绝对值，该函数对于整数类型会返回对应的无符号整数。
 - 最后通过 `std::cout` 输出结果。

### 2. 针对浮点数类型
```cpp
#include <iostream>
#include <cmath>

int main() {
    double num = -3.14;
    double absValue = std::fabs(num);
    std::cout << "浮点数 " << num << " 的绝对值是: " << absValue << std::endl;
    return 0;
}
```
这里：
 - 定义了 `double` 类型变量 `num` 并初始化为 `-3.14`。
 - 对于浮点数，使用 `<cmath>` 库中的 `std::fabs` 函数来计算其绝对值，它返回与输入参数同类型的浮点数。
 - 最后输出浮点数的绝对值。

### 3. 自定义绝对值函数
```cpp
#include <iostream>

// 自定义函数计算整数绝对值
int myAbs(int num) {
    return num < 0? -num : num;
}

// 自定义函数计算浮点数绝对值
double myAbs(double num) {
    return num < 0? -num : num;
}

int main() {
    int intNum = -5;
    double doubleNum = -2.718;

    int intAbsValue = myAbs(intNum);
    double doubleAbsValue = myAbs(doubleNum);

    std::cout << "自定义函数：整数 " << intNum << " 的绝对值是: " << intAbsValue << std::endl;
    std::cout << "自定义函数：浮点数 " << doubleNum << " 的绝对值是: " << doubleAbsValue << std::endl;

    return 0;
}
```
在这个示例中：
 - 定义了两个重载的 `myAbs` 函数，一个用于计算 `int` 类型的绝对值，另一个用于计算 `double` 类型的绝对值。
 - 在 `myAbs` 函数内部，使用三元运算符判断数字是否为负数，如果是则返回其相反数，否则返回数字本身。
 - 在 `main` 函数中，分别定义了 `int` 类型和 `double` 类型的变量，并调用自定义的 `myAbs` 函数计算它们的绝对值并输出。 