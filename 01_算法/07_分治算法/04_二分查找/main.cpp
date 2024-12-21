#include <iostream>
#include <vector>

using namespace std;

// 二分查找函数
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15 };
    int target = 7;
    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "元素 " << target << " 在数组中的索引为: " << result << endl;
    }
    else {
        cout << "元素 " << target << " 不在数组中" << endl;
    }
    return 0;
}