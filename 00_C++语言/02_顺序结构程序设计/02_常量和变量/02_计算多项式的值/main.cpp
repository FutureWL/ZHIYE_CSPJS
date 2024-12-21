#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;  // 多项式的次数
    cout << "请输入多项式的次数：";
    cin >> n;

    double* coefficients = new  double[n + 1];  // 存储多项式各项系数的数组，下标从0到n，使用后必须释放
    cout << "请依次输入多项式各项的系数（从最高次项系数开始）：";
    for (int i = n; i >= 0; --i) {
        cin >> coefficients[i];
    }

    double x;  // 自变量的值
    cout << "请输入自变量 x 的值：";
    cin >> x;

    double result = 0;
    for (int i = n; i >= 0; --i) {
        result += coefficients[i] * pow(x, i);
    }

    cout << "该多项式在 x = " << x << " 时的值为：" << result << endl;

    delete[] coefficients; // 释放动态创建的数组
    return 0;
}