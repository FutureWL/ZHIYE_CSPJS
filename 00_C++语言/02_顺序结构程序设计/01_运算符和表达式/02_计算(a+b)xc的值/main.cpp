#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    // 提示用户输入三个整数
    cout << "请输入整数 a 的值：";
    cin >> a;
    cout << "请输入整数 b 的值：";
    cin >> b;
    cout << "请输入整数 c 的值：";
    cin >> c;

    int result = (a + b) * c;
    // 输出计算结果
    cout << "表达式 (a + b) * c 的值为：" << result << endl;

    return 0;
}