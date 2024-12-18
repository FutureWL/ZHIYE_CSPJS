#include <iostream>
#include <iomanip>

using namespace std;

// 计算杨辉三角中指定位置的数值（使用递推）
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

// 打印杨辉三角前n行的函数
void printPascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << setw(6) << binomialCoefficient(i, j);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "请输入要打印的杨辉三角的行数: ";
    cin >> n;
    printPascalTriangle(n);
    return 0;
}