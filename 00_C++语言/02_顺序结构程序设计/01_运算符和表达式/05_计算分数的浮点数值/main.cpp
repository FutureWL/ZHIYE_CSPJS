#include <iostream>
using namespace std;

int main() {
    int numerator, denominator;
    // 提示用户输入分子
    cout << "请输入分数的分子：";
    cin >> numerator;
    // 提示用户输入分母
    cout << "请输入分数的分母：";
    cin >> denominator;

    if (denominator == 0) {
        // 检查分母是否为0，若为0则输出错误提示并结束程序
        cout << "分母不能为0，请重新输入合法的分母。" << endl;
        return -1;
    }

    double result = static_cast<double>(numerator) / denominator;
    // 输出计算结果
    cout << "该分数对应的浮点数值是：" << result << endl;

    return 0;
}