#include <iostream>
using namespace std;

int main() {
    double celsius;  // 用于存储摄氏温度值
    cout << "请输入摄氏温度：";
    cin >> celsius;

    double fahrenheit = celsius * 9 / 5 + 32;  // 摄氏温度转华氏温度的公式

    double resultArray[1];  // 定义数组来存储转换后的结果，这里只存一个值所以大小为1
    resultArray[0] = fahrenheit;

    cout << celsius << "摄氏度对应的华氏温度是：" << resultArray[0] << "华氏度" << endl;

    return 0;
}