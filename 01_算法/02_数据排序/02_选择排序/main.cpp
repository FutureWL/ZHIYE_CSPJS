#include <iostream>
#include <vector>

using namespace std;

// 交换两个元素的值
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 选择排序函数
void selectionSort(vector<int>& arr) {
    // 获得序列长度
    int n = arr.size();
    // 从零开始遍历内容
    for (int i = 0; i < n - 1; ++i) {
        // 设计排序下标
        int minIndex = i;
        // 遍历后序序列
        for (int j = i + 1; j < n; ++j) {
            // 如果后序元素小于待判断元素
            if (arr[j] < arr[minIndex]) {
                // 将排序找到的最小值下标移动到此位置
                minIndex = j;
            }
        }
        // 如果最小值不等于待排序元素
        if (minIndex != i) {
            // 将找到的最小值和当前值交换
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    // 初始化待排序数组
    vector<int> numbers = { 5, 3, 8, 6, 7 };
    // 执行选择排序
    selectionSort(numbers);
    // 将数组遍历输出
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}