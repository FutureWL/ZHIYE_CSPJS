#include <iostream>

using namespace std;

// 汉诺塔移动步骤的递归函数
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        std::cout << "将第1个圆盘从 " << from << " 柱移到 " << to << " 柱" << endl;
        return;
    }
    hanoi(n - 1, from, to, aux);
    std::cout << "将第" << n << "个圆盘从 " << from << " 柱移到 " << to << " 柱" << endl;
    hanoi(n - 1, aux, from, to);
}

int main() {
    int numDisks;
    cout << "请输入汉诺塔圆盘的个数: ";
    cin >> numDisks;
    hanoi(numDisks, 'A', 'B', 'C');
    return 0;
}