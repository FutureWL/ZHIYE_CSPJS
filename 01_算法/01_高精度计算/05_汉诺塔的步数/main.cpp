#include <iostream>

using namespace std;

// 计算汉诺塔移动步数的函数
int hanoiSteps(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * hanoiSteps(n - 1) + 1;
}

int main() {
    int numDisks;
    cout << "请输入汉诺塔圆盘的个数: ";
    cin >> numDisks;

    int steps = hanoiSteps(numDisks);
    cout << "移动 " << numDisks << " 个圆盘需要的步数为: " << steps << endl;
    return 0;
}