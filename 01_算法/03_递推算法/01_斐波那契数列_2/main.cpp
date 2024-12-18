#include <iostream>

using namespace std;

// 计算斐波那契数列第n项的函数（使用递推）
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, result;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    cout << "请输入要计算的斐波那契数列的项数: ";
    cin >> n;
    int fib = fibonacci(n);
    cout << "斐波那契数列第" << n << "项的值为: " << fib << endl;
    return 0;
}