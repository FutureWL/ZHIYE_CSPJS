#include <iostream>
#include <vector>

using namespace std;

// 冒泡排序函数
void bubbleSort(vector<int>& arr) {
    // 获得序列长度
    int n = arr.size();
    // 遍历所有元素
    for (int i = 0; i < n - 1; ++i) {
        // 从初始值开始，遍历至选择的元素
        for (int j = 0; j < n - i - 1; ++j) {
            // 判断当前值比后序的值大
            if (arr[j] > arr[j + 1]) {
                // 交换相邻元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // 获得一个待排序的数列
    vector<int> numbers = { 9, 5, 7, 3, 1 };
    // 执行冒泡排序
    bubbleSort(numbers);
    // 遍历输出排序完毕的数据
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}