#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 反转字符串
string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}

// 高精度减法
string 高精度减法(string num1, string num2) {
    // 确保num1大于num2
    if (num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2)) {
        swap(num1, num2);
    }

    // 反转两个字符串
    num1 = reverseString(num1);
    num2 = reverseString(num2);

    string result = "";
    int carry = 0;  // 借位

    for (int i = 0; i < num2.size(); i++) {
        int sub = (num1[i] - '0') - (num2[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result += (sub + '0');
    }

    // 处理剩余的num1部分
    for (int i = num2.size(); i < num1.size(); i++) {
        int sub = (num1[i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result += (sub + '0');
    }

    // 去除前导0
    size_t start = result.find_first_not_of('0');
    if (start != string::npos) {
        result = result.substr(start);
    }
    else {
        result = "0";  // 只有当两个数相等时，结果为0
    }

    // 反转回正常顺序
    return reverseString(result);
}

int main() {
    string num1, num2;
    cout << "请输入第一个数: ";
    cin >> num1;
    cout << "请输入第二个数: ";
    cin >> num2;

    string result = 高精度减法(num1, num2);
    cout << "减法结果是: " << result << endl;

    return 0;
}