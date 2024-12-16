以下是使用C++实现归并排序的代码示例：

```cpp
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
```

下面来详细解释这段代码的实现逻辑：

### 1. `merge` 函数（合并操作）
- **确定子数组长度及创建临时数组**：
首先根据传入的参数 `left`、`mid`、`right` 来确定左右两个子数组的长度 `n1` 和 `n2`（`int n1 = mid - left + 1;`，`int n2 = right - mid;`），然后分别创建两个临时的向量 `L` 和 `R` 用于存放左右两个子数组的元素，接着通过循环将原数组中对应区间的元素拷贝到这两个临时数组中（`for (int i = 0; i < n1; i++)` 和 `for (int j = 0; j < n2; j++)` 这两个循环）。
- **合并临时数组到原数组**：
使用三个指针 `i`（指向 `L` 数组当前元素）、`j`（指向 `R` 数组当前元素）、`k`（指向原数组 `arr` 中当前合并的位置），通过循环比较 `L[i]` 和 `R[j]` 的大小，将较小的元素先放入原数组 `arr` 中对应的位置（`while (i < n1 && j < n2)` 循环）。当其中一个临时数组的元素全部放入原数组后，通过后面两个 `while` 循环，将另一个临时数组剩余的元素依次拷贝到原数组 `arr` 中相应位置。

### 2. `mergeSort` 函数（归并排序主函数）
- **递归划分**：
先判断当前要排序的区间范围是否合法（`if (left < right)`），如果合法，则计算中间位置 `mid`（`int mid = left + (right - left) / 2;`），接着分别对左半部分（`mergeSort(arr, left, mid);`）和右半部分（`mergeSort(arr, mid + 1, right);`）进行递归调用，不断将数组划分成更小的子数组，直到子数组只有一个元素（此时认为它是已排序的）。
- **合并操作**：
在左右子数组都完成递归排序后，调用 `merge` 函数将两个已排序的子数组合并成一个更大的已排序数组，如此不断合并，最终完成整个数组的排序。

### 3. `main` 函数
- 定义了一个示例数组 `arr`，先输出排序前数组元素的情况。
- 然后调用 `mergeSort` 函数对整个数组（区间是 `0` 到 `n - 1`，`n` 为数组长度）进行归并排序。
- 最后输出排序后数组元素的情况，展示归并排序的结果。

归并排序的时间复杂度为 $O(nlogn)$，空间复杂度在不进行优化的情况下为 $O(n)$，它是一种稳定的排序算法，在处理各种数据规模时都能有比较稳定且高效的排序表现。 


