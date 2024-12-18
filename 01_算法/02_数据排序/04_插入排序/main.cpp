#include <iostream>
#include <vector>

using namespace std;

// 插入排序函数
void insertionSort(vector<int>& arr) {
    // 获得序列长度
    int n = arr.size();
    // 从第1个元素开始，遍历到最后一个元素
    for (int i = 1; i < n; ++i) {
        // 获得第一个数列元素
        int key = arr[i];
        // 获得第二个待排序元素
        int j = i - 1;
        // 和已经排序的数组对比，将此元素比较，将元素插入序列
        while (j >= 0 && arr[j] > key) {
            // 序列前序插入排序
            arr[j + 1] = arr[j];
            j--;
        }
        // 序列后序插入排序
        arr[j + 1] = key;
    }
}

int main() {
    // 初始化待排序序列
    vector<int> numbers = { 12, 11, 13, 5, 6 };
    // 插入排序
    insertionSort(numbers);
    // 将排序后的序列，有序输出
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}