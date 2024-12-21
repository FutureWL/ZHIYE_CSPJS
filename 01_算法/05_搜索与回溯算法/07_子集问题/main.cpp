#include <iostream>
#include <vector>

using namespace std;

// 回溯函数，用于生成子集
void subsetsUtil(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
    // 每一种当前的子集情况都是一个有效解，将其加入结果集
    result.push_back(currentSubset);

    for (int i = start; i < nums.size(); i++) {
        // 将当前数字加入当前子集
        currentSubset.push_back(nums[i]);
        // 继续递归，从下一个位置开始生成包含更多元素的子集
        subsetsUtil(nums, i + 1, currentSubset, result);
        // 回溯，移除刚才加入的数字，尝试其他可能的子集组合
        currentSubset.pop_back();
    }
}

// 解决子集问题的主函数
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> currentSubset;
    subsetsUtil(nums, 0, currentSubset, result);
    return result;
}

int main() {
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> result = subsets(nums);
    cout << "给定集合的所有子集如下：" << endl;
    for (vector<int> subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}