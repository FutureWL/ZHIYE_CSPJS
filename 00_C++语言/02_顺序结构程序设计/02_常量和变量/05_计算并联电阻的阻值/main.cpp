#include <iostream>
using namespace std;

int main() {
    double resistance1, resistance2;
    cout << "请输入第一个电阻的阻值：";
    cin >> resistance1;
    cout << "请输入第二个电阻的阻值：";
    cin >> resistance2;
    double totalResistance = 1 / ((1 / resistance1) + (1 / resistance2));
    cout << "这两个电阻并联后的阻值为：" << totalResistance << "欧姆" << endl;
    return 0;
}