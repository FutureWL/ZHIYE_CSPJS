#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 回溯函数，用于生成括号组合
void generateParenthesisUtil(int n, int open, int close, string current, vector<string>& result) {
    if (open == n && close == n) {
        // 当左右括号都用完了，说明得到了一个合法的括号组合，将其加入结果集
        result.push_back(current);
        return;
    }

    if (open < n) {
        // 如果左括号还没用完，添加一个左括号继续递归
        generateParenthesisUtil(n, open + 1, close, current + "(", result);
    }

    if (close < open) {
        // 如果右括号数量小于左括号数量，添加一个右括号继续递归
        generateParenthesisUtil(n, open, close + 1, current + ")", result);
    }
}

// 解决生成括号问题的主函数
vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisUtil(n, 0, 0, "", result);
    return result;
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    cout << "n为 " << n << " 时生成的合法括号组合如下：" << endl;
    for (string str : result) {
        cout << str << endl;
    }
    return 0;
}