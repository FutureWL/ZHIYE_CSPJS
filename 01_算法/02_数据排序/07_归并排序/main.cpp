#include <iostream>
#include <vector>

using namespace std;

// 合并两个已排序的子数组
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    vector<int> L(n1), R(n2);

    // 拷贝数据到临时数组L和R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝L剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝R剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序主函数
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 对左半部分排序
        mergeSort(arr, left, mid);

        // 对右半部分排序
        mergeSort(arr, mid + 1, right);

        // 合并两个已排序的部分
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6 };
    int n = arr.size();

    cout << "排序前的数组: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "排序后的数组: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}