#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 交换两个元素的位置
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 回溯函数，用于生成全排列
void permuteUtil(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permuteUtil(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

// 生成全排列的主函数
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteUtil(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> result = permute(nums);

    cout << "全排列结果如下：" << endl;
    for (vector<int> perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}