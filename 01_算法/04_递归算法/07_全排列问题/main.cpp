#include <iostream>
#include <vector>

using namespace std;

// 交换两个元素的位置
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 递归生成全排列的函数
void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

int main() {
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> result;
    permute(nums, 0, result);

    cout << "全排列结果如下：" << endl;
    for (vector<int> perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}