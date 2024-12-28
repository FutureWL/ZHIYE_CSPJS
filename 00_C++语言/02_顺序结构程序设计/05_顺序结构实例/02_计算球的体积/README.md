1. **使用`const`常量和`M_PI`宏（C++标准库）**
   - 在C++中，可以利用`<cmath>`库中的`M_PI`宏来表示圆周率`π`，通过球体积公式`V = \frac{4}{3}πr^3`计算球的体积。
```cpp
#include <iostream>
#include <cmath>

int main() {
    // 定义球的半径
    const double radius = 5.0;
    // 计算球的体积
    double volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    std::cout << "半径为 " << radius << " 的球的体积是: " << volume << std::endl;
    return 0;
}
```
   - 在上述代码中：
     - 首先定义了一个`const double`类型的常量`radius`表示球的半径，这里设置为`5.0`。
     - 然后根据球体积公式计算体积，`std::pow(radius, 3)`用于计算半径的立方。
     - 最后通过`std::cout`输出球的体积。

2. **从用户获取半径并使用`std::format`（C++20及以上）**
   - 这个示例允许用户输入球的半径，并使用C++20引入的`<format>`库进行格式化输出。
```cpp
#include <iostream>
#include <cmath>
#include <format>

int main() {
    double radius;
    std::cout << "请输入球的半径: ";
    std::cin >> radius;
    double volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    std::cout << std::format("半径为 {:.2f} 的球的体积是: {:.4f}\n", radius, volume);
    return 0;
}
```
   - 在这个代码中：
     - 首先提示用户输入球的半径，并将输入值存储在`radius`变量中。
     - 计算球体积的方式与上一个示例相同。
     - 使用`std::format`函数进行格式化输出，`{:.2f}`表示将半径输出为保留两位小数的浮点数，`{:.4f}`表示将体积输出为保留四位小数的浮点数。

3. **考虑精度和类型选择**
   - 如果需要更高的精度，可以使用`long double`类型。
```cpp
#include <iostream>
#include <cmath>

int main() {
    long double radius = 5.0L;
    long double volume = (4.0L / 3.0L) * std::acos(-1.0L) * std::pow(radius, 3);
    std::cout << "半径为 " << radius << " 的球的体积是: " << volume << std::endl;
    return 0;
}
```
   - 这里使用`long double`类型，`std::acos(-1.0L)`用于获取`π`的`long double`表示，以适应`long double`类型的计算，从而提高精度。

这些示例展示了在C++中计算球体积的不同方法，你可以根据实际需求选择合适的实现。 