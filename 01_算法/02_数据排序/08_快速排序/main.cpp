#include <iostream>
#include <vector>

using namespace std;

// 交换两个元素的函数
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 划分函数，选择一个基准元素，将数组划分为左右两部分
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // 通常选择最后一个元素作为基准元素
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序主函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // 对基准元素左边的子数组进行快速排序
        quickSort(arr, low, pivotIndex - 1);

        // 对基准元素右边的子数组进行快速排序
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = { 10, 8, 2, 7, 3, 1, 9, 5 };
    int n = arr.size();

    cout << "排序前的数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "排序后的数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}