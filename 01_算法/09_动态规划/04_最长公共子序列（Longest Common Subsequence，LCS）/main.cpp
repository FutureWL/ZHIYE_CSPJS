#include <iostream>
#include <vector>

using namespace std;

// 使用动态规划计算最长公共子序列的长度
int longestCommonSubsequence(vector<int>& seq1, vector<int>& seq2) {
    int m = seq1.size();
    int n = seq2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<int> seq1 = { 1, 3, 4, 5, 6, 7, 7, 8 };
    vector<int> vec = { 3, 5, 7, 4, 8, 6, 7, 8, 2 };
    vector<int>& seq2 = vec;
    int result = longestCommonSubsequence(seq1, seq2);
    cout << "最长公共子序列的长度为: " << result << endl;
    return 0;
}