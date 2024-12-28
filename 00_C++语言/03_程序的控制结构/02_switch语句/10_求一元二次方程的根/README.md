1. **案例分析**：
   - 对于一元二次方程 \(ax^2 + bx + c = 0\)（\(a\neq0\)），其判别式 \(\Delta = b^2 - 4ac\)。根据 \(\Delta\) 的值来确定方程根的情况：
     - 当 \(\Delta > 0\) 时，方程有两个不同的实根 \(x_1=\frac{-b + \sqrt{\Delta}}{2a}\) 和 \(x_2=\frac{-b - \sqrt{\Delta}}{2a}\)。
     - 当 \(\Delta = 0\) 时，方程有一个实根 \(x = -\frac{b}{2a}\)。
     - 当 \(\Delta < 0\) 时，方程有两个虚根 \(x_1 = -\frac{b}{2a} + i\frac{\sqrt{-\Delta}}{2a}\) 和 \(x_2 = -\frac{b}{2a} - i\frac{\sqrt{-\Delta}}{2a}\)。
   - 我们将使用 `switch` 语句来根据 \(\Delta\) 的不同情况进行处理。
2. **代码实现**：
```cpp
#include <iostream>
#include <cmath>
#include <complex>

int main() {
    double a, b, c;
    std::cout << "请输入一元二次方程 ax^2 + bx + c = 0 的系数 a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "a 不能为 0，这不是一元二次方程。" << std::endl;
        return 1;
    }

    double discriminant = b * b - 4 * a * c;
    int rootCase;
    if (discriminant > 0) {
        rootCase = 1;
    } else if (discriminant == 0) {
        rootCase = 2;
    } else {
        rootCase = 3;
    }

    switch (rootCase) {
    case 1: {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "方程有两个不同的实根: " << std::endl;
        std::cout << "x1 = " << root1 << std::endl;
        std::cout << "x2 = " << root2 << std::endl;
        break;
    }
    case 2: {
        double root = -b / (2 * a);
        std::cout << "方程有一个实根: " << std::endl;
        std::cout << "x = " << root << std::endl;
        break;
    }
    case 3: {
        std::complex<double> root1(-b / (2 * a), sqrt(-discriminant) / (2 * a));
        std::complex<double> root2(-b / (2 * a), -sqrt(-discriminant) / (2 * a));
        std::cout << "方程有两个虚根: " << std::endl;
        std::cout << "x1 = " << root1 << std::endl;
        std::cout << "x2 = " << root2 << std::endl;
        break;
    }
    }

    return 0;
}
```
3. **代码说明**：
   - **变量声明**：
     - `a`、`b`、`c` 用于存储一元二次方程的系数。
     - `discriminant` 用于存储判别式 \(\Delta\) 的值。
     - `rootCase` 用于标记根的情况，根据 \(\Delta\) 的值确定，1 表示有两个不同实根，2 表示有一个实根，3 表示有两个虚根。
   - **输入获取与合法性检查**：
     - 使用 `std::cout` 提示用户输入方程的系数 `a`、`b`、`c`，并通过 `std::cin` 获取输入值。
     - 检查 `a` 是否为 0，如果是则输出错误信息并结束程序，因为此时不是一元二次方程。
   - **计算判别式并确定根的情况**：
     - 计算判别式 `discriminant`。
     - 根据 `discriminant` 的值确定 `rootCase` 的值。
   - **`switch` 语句处理不同根的情况**：
     - `case 1`：当 `rootCase` 为 1 时，计算并输出两个不同的实根。
     - `case 2`：当 `rootCase` 为 2 时，计算并输出一个实根。
     - `case 3`：当 `rootCase` 为 3 时，使用 `std::complex<double>` 类型来表示并输出两个虚根。每个 `case` 分支结束时使用 `break` 防止程序继续执行下一个 `case`。

这样就通过 `switch` 语句实现了求一元二次方程根的功能。 