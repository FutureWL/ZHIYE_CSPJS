1. **已知底和高求三角形面积**
   - 根据三角形面积公式\(S = \frac{1}{2}ah\)（其中\(a\)为底，\(h\)为高），以下是C++实现代码：
```cpp
#include <iostream>

int main() {
    double base, height;
    std::cout << "请输入三角形的底: ";
    std::cin >> base;
    std::cout << "请输入三角形的高: ";
    std::cin >> height;

    double area = 0.5 * base * height;
    std::cout << "三角形的面积为: " << area << std::endl;

    return 0;
}
```
   - 在上述代码中：
     - 首先声明两个 `double` 类型的变量 `base` 和 `height` 用于存储用户输入的底和高。
     - 提示用户输入底和高的值。
     - 根据面积公式计算三角形面积，并将结果存储在 `area` 变量中。
     - 最后输出三角形的面积。

2. **已知三条边求三角形面积（海伦公式）**
   - 海伦公式为\(S=\sqrt{p(p - a)(p - b)(p - c)}\)，其中\(a\)、\(b\)、\(c\)为三角形的三条边，\(p=\frac{a + b + c}{2}\)。
```cpp
#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cout << "请输入三角形的三条边: ";
    std::cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) / 2;
        double area = std::sqrt(p * (p - a) * (p - b) * (p - c));
        std::cout << "三角形的面积为: " << area << std::endl;
    } else {
        std::cout << "输入的三条边不能构成三角形。" << std::endl;
    }

    return 0;
}
```
   - 代码说明：
     - 声明三个 `double` 类型变量 `a`、`b`、`c` 用于存储三角形的三条边。
     - 提示用户输入三条边的值。
     - 通过三角形三边关系判断输入的三条边能否构成三角形。如果能构成三角形，则计算半周长 `p`，再根据海伦公式计算面积并输出；否则，输出提示信息表明输入的边不能构成三角形。

3. **已知两点坐标求三角形面积（假设一个顶点在原点）**
   - 假设三角形一个顶点在原点\((0, 0)\)，另外两个顶点坐标为\((x_1, y_1)\)和\((x_2, y_2)\)，则面积公式为\(S=\frac{1}{2}|x_1y_2 - x_2y_1|\)。
```cpp
#include <iostream>
#include <cmath>

int main() {
    double x1, y1, x2, y2;
    std::cout << "请输入第一个点的坐标(x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "请输入第二个点的坐标(x2, y2): ";
    std::cin >> x2 >> y2;

    double area = 0.5 * std::abs(x1 * y2 - x2 * y1);
    std::cout << "三角形的面积为: " << area << std::endl;

    return 0;
}
```
   - 代码逻辑：
     - 声明四个 `double` 类型变量 `x1`、`y1`、`x2`、`y2` 用于存储两个点的坐标。
     - 提示用户输入两个点的坐标值。
     - 根据给定公式计算三角形面积并输出，使用 `std::abs` 函数取绝对值以确保面积为非负值。