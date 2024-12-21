#include <iostream>
#include <vector>

using namespace std;

// 递归计算组合的函数
void combine(int n, int m, int start, vector<int>& cur, vector<vector<int>>& result) {
    if (cur.size() == m) {
        result.push_back(cur);
        return;
    }
    for (int i = start; i <= n; i++) {
        cur.push_back(i);
        combine(n, m, i + 1, cur, result);
        cur.pop_back();
    }
}

int main() {
    int n = 5;
    int m = 3;
    vector<int> cur;
    vector<vector<int>> result;
    combine(n, m, 1, cur, result);

    cout << "从 " << n << " 个元素中取 " << m << " 个元素的组合情况如下：" << endl;
    for (vector<int> comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
