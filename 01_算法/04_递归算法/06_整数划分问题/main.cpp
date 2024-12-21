#include <iostream>

using namespace std;

// 递归计算整数n的划分个数的函数
int partition(int n, int m) {
    if (n == 1 || m == 1) {
        return 1;
    }
    if (n < m) {
        return partition(n, n);
    }
    if (n == m) {
        return 1 + partition(n, m - 1);
    }
    return partition(n, m - 1) + partition(n - m, m);
}

int main() {
    int n;
    cout << "请输入要进行划分的正整数: ";
    cin >> n;
    int result = partition(n, n);
    cout << "整数 " << n << " 的划分个数为: " << result << endl;
    return 0;
}