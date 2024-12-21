#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用动态规划计算最长递增子序列的长度
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    int result = lengthOfLIS(nums);
    cout << "最长递增子序列的长度为: " << result << endl;
    return 0;
}