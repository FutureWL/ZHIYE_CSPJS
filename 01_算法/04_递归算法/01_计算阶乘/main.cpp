#include <iostream>

using namespace std;

// 递归计算n的阶乘的函数
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "请输入要计算阶乘的正整数: ";
    cin >> n;
    int result = factorial(n);
    cout << n << " 的阶乘为: " << result << endl;
    return 0;
}