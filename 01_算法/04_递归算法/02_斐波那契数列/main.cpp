#include <iostream>

using namespace std;

// 递归计算斐波那契数列第n项的函数
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "请输入要计算的斐波那契数列的项数: ";
    cin >> n;
    int result = fibonacci(n);
    cout << "斐波那契数列第" << n << "项的值为: " << result << endl;
    return 0;
}