#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 判断一个字符串是否是回文串
bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 回溯函数，用于寻找分割回文串的所有方案
void partitionUtil(const string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result) {
    if (start == s.length()) {
        // 当已经处理完整个字符串，说明找到了一种分割方案，将其加入结果集
        result.push_back(currentPartition);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        string subStr = s.substr(start, i - start + 1);
        if (isPalindrome(subStr)) {
            // 如果当前子串是回文串，将其加入当前分割方案
            currentPartition.push_back(subStr);
            // 继续递归，从下一个位置开始分割
            partitionUtil(s, i + 1, currentPartition, result);
            // 回溯，移除刚才加入的子串，尝试其他分割方式
            currentPartition.pop_back();
        }
    }
}

// 解决分割回文串问题的主函数
vector<vector<string>> partition(const string& s) {
    vector<vector<string>> result;
    vector<string> currentPartition;
    partitionUtil(s, 0, currentPartition, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);
    cout << "字符串 " << s << " 的所有分割方案如下：" << endl;
    for (vector<string> partitionScheme : result) {
        for (string str : partitionScheme) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}