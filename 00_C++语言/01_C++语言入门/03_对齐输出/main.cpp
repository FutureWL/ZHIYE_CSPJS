#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num1 = 10;
    int num2 = 100;
    double num3 = 3.1415926;

    // 设置宽度为10进行对齐输出
    cout << setw(10) << num1 << setw(10) << num2 << setw(10) << num3 << endl;

    return 0;
}