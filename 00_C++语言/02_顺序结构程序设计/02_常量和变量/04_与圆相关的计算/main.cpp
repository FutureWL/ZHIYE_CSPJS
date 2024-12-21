#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    const double PI = 3.1415926;  // 定义圆周率常量
    double radius;  // 存储圆的半径
    cout << "请输入圆的半径：";
    cin >> radius;

    // 计算圆的周长，公式为 C = 2 * π * r
    double circumference = 2 * PI * radius;
    // 计算圆的面积，公式为 S = π * r * r
    double area = PI * radius * radius;

    cout << "圆的周长为：" << fixed << setprecision(2) << circumference << endl;
    cout << "圆的面积为：" << fixed << setprecision(2) << area << endl;

    return 0;
}
