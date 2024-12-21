#include <iostream>
#include <string>

using namespace std;

// 递归判断字符串是否为回文的函数
bool isPalindrome(const char* str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string input = "racecar";
    const char* str = input.c_str();
    bool result = isPalindrome(str, 0, input.length() - 1);
    if (result) {
        cout << "该字符串是回文" << endl;
    }
    else {
        cout << "该字符串不是回文" << endl;
    }
    return 0;
}