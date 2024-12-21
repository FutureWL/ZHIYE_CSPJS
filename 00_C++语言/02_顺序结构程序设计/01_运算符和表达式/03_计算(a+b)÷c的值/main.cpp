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

    if (c == 0) {
        // 检查除数是否为0，若为0则输出错误提示并结束程序
        cout << "除数不能为0，请重新输入合法的整数 c。" << endl;
        return -1;
    }

    int result = (a + b) / c;
    // 输出计算结果
    cout << "表达式 (a + b) / c 的值为：" << result << endl;

    return 0;
}
