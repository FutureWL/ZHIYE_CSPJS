#include <iostream>

using namespace std;

// 计算n的阶乘的函数（使用递推）
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cout << "请输入要计算阶乘的正整数: ";
    cin >> n;
    int fact = factorial(n);
    cout << n << "的阶乘为: " << fact << endl;
    return 0;
}