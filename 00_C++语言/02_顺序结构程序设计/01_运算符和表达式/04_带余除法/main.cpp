#include <iostream>
using namespace std;

int main() {
    int dividend, divisor;
    // 提示用户输入被除数
    cout << "请输入被除数：";
    cin >> dividend;
    // 提示用户输入除数
    cout << "请输入除数：";
    cin >> divisor;

    if (divisor == 0) {
        // 检查除数是否为0，若为0则输出错误提示并结束程序
        cout << "除数不能为0，请重新输入合法的除数。" << endl;
        return -1;
    }

    int quotient = dividend / divisor;  // 计算商
    int remainder = dividend % divisor;  // 计算余数

    cout << dividend << "除以" << divisor << "的商是：" << quotient << endl;
    cout << dividend << "除以" << divisor << "的余数是：" << remainder << endl;

    return 0;
}