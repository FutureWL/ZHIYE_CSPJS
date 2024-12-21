#include <iostream>
#include <vector>

using namespace std;

// 回溯函数，用于寻找组合总和的解
void combinationSumUtil(vector<int>& candidates, int target, int start, vector<int>& currentCombination, vector<vector<int>>& result) {
    if (target == 0) {
        // 当目标值减到0，说明找到了一种满足和为目标值的组合，将其加入结果集
        result.push_back(currentCombination);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            // 将当前数字加入当前组合
            currentCombination.push_back(candidates[i]);
            // 继续递归，更新目标值（减去当前加入的数字），继续从当前位置开始找（可重复选取）
            combinationSumUtil(candidates, target - candidates[i], i, currentCombination, result);
            // 回溯，移除刚才加入的数字，尝试其他可能的组合
            currentCombination.pop_back();
        }
    }
}

// 解决组合总和问题的主函数
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> currentCombination;
    combinationSumUtil(candidates, target, 0, currentCombination, result);
    return result;
}

int main() {
    vector<int> candidates = { 2, 3, 6, 7 };
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
    cout << "满足组合总和为 " << target << " 的组合情况如下：" << endl;
    for (vector<int> comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}