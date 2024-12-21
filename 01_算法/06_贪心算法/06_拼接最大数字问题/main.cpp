#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 比较函数，用于确定两个数字拼接后的大小顺序，以决定排序方式
bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

// 贪心算法实现拼接最大数字
string largestNumber(vector<int>& nums) {
    vector<string> numStrs;
    for (int num : nums) {
        numStrs.push_back(to_string(num));
    }
    sort(numStrs.begin(), numStrs.end(), compare);
    string result;
    for (string numStr : numStrs) {
        result += numStr;
    }
    if (result[0] == '0') {
        return "0";
    }
    return result;
}

int main() {
    vector<int> nums = { 3, 30, 34, 5, 9 };
    string largest = largestNumber(nums);
    cout << "拼接出的最大数字为: " << largest << endl;
    return 0;
}