#include <iostream>
#include <string>

using namespace std;

// 递归计算字符串长度的函数
int stringLength(const char* str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + stringLength(str + 1);
}

int main() {
    string input = "Hello";
    const char* str = input.c_str();
    int length = stringLength(str);
    cout << "字符串 " << input << " 的长度为: " << length << endl;
    return 0;
}