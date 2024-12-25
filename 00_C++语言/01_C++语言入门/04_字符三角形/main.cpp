#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入三角形的行数: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        // 打印空格，用于控制三角形的形状，每行空格数逐渐减少
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        // 打印字符，每行字符数逐渐增加
        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}