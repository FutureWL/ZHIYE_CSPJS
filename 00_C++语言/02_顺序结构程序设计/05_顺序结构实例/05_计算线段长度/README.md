1. **基于平面直角坐标系中两点间距离公式**
   - 在平面直角坐标系中，已知两点\(A(x_1, y_1)\)和\(B(x_2, y_2)\)，两点间线段的长度\(d\)可以通过公式\(d = \sqrt{(x_2 - x_1)^2+(y_2 - y_1)^2}\)计算。
   - 以下是C++ 代码实现：
```cpp
#include <iostream>
#include <cmath>

// 计算两点间线段长度的函数
double calculateSegmentLength(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx+dy * dy);
}

int main() {
    double x1, y1, x2, y2;
    std::cout << "请输入第一个点的坐标(x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "请输入第二个点的坐标(x2, y2): ";
    std::cin >> x2 >> y2;

    double length = calculateSegmentLength(x1, y1, x2, y2);
    std::cout << "两点间线段的长度为: " << length << std::endl;

    return 0;
}
```
   - 在上述代码中：
     - 定义了一个函数 `calculateSegmentLength`，该函数接受四个 `double` 类型的参数，分别表示两个点的坐标。
     - 在函数内部，先计算两点在\(x\)轴和\(y\)轴方向上的差值 `dx` 和 `dy`，然后根据距离公式计算并返回线段长度。
     - 在 `main` 函数中，提示用户输入两个点的坐标，调用 `calculateSegmentLength` 函数计算线段长度，并将结果输出。

2. **三维空间中两点间线段长度**
   - 在三维空间中，已知两点\(A(x_1, y_1, z_1)\)和\(B(x_2, y_2, z_2)\)，两点间线段的长度\(d\)的公式为\(d=\sqrt{(x_2 - x_1)^2+(y_2 - y_1)^2+(z_2 - z_1)^2}\)。
   - 代码如下：
```cpp
#include <iostream>
#include <cmath>

// 计算三维空间两点间线段长度的函数
double calculate3DSegmentLength(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return std::sqrt(dx * dx+dy * dy+dz * dz);
}

int main() {
    double x1, y1, z1, x2, y2, z2;
    std::cout << "请输入第一个点的坐标(x1, y1, z1): ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "请输入第二个点的坐标(x2, y2, z2): ";
    std::cin >> x2 >> y2 >> z2;

    double length = calculate3DSegmentLength(x1, y1, z1, x2, y2, z2);
    std::cout << "三维空间中两点间线段的长度为: " << length << std::endl;

    return 0;
}
```
   - 此代码与二维情况类似，只是增加了\(z\)坐标的处理。`calculate3DSegmentLength` 函数接受六个参数表示三维空间中两个点的坐标，按照三维空间距离公式计算并返回线段长度。在 `main` 函数中提示用户输入三维空间两个点的坐标，调用函数计算并输出线段长度。 