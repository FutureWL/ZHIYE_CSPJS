以下是使用C++实现快速排序的代码示例：

```cpp
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
```

下面详细解释一下这段代码的实现逻辑：

### 1. `swap` 函数
这是一个简单的辅助函数，用于交换两个整数的位置，通过引入一个临时变量 `temp`，实现了两个元素值的互换，方便后续在划分等操作中交换数组元素的位置。

### 2. `partition` 函数（划分操作）
- **选择基准元素**：
通常选取数组中最后一个元素（`int pivot = arr[high];`）作为本次划分的基准元素，当然也可以选择其他方式来确定基准元素，比如随机选择等。
- **初始化指针并遍历比较**：
初始化指针 `i` 为 `low - 1`，然后从 `low` 开始到 `high - 1` 遍历数组（`for (int j = low; j < high; j++)`），当遇到元素 `arr[j]` 小于等于基准元素 `pivot` 时，先将指针 `i` 向后移动一位（`i++;`），然后交换 `arr[i]` 和 `arr[j]` 的位置，这样就把小于等于基准元素的数不断放到左边部分。
- **放置基准元素**：
遍历完后，将基准元素放到合适的位置（即指针 `i + 1` 的位置），通过交换 `arr[i + 1]` 和 `arr[high]` 的操作，使得基准元素左边的元素都小于等于它，右边的元素都大于它，最后返回基准元素所在的索引位置（`i + 1`）。

### 3. `quickSort` 函数（快速排序主函数）
- **递归条件判断**：
首先判断当前要排序的区间范围是否合法（`if (low < high)`），如果合法，说明子数组中至少有两个元素，需要进行划分和进一步排序。
- **划分与递归排序**：
调用 `partition` 函数得到基准元素的索引 `pivotIndex`，然后分别对基准元素左边的子数组（`quickSort(arr, low, pivotIndex - 1);`）和右边的子数组（`quickSort(arr, pivotIndex + 1, high);`）进行递归调用快速排序，不断将子数组划分并排序，直到子数组的元素个数小于等于1，此时认为该子数组已经是有序的了。

### 4. `main` 函数
- 定义了一个示例数组 `arr`，先输出排序前数组元素的情况，方便查看初始状态。
- 接着调用 `quickSort` 函数对整个数组（区间是从 `0` 到 `n - 1`，`n` 为数组长度）进行快速排序。
- 最后输出排序后数组元素的情况，展示快速排序的结果。

快速排序在平均情况下时间复杂度为 $O(nlogn)$，但在最坏情况下（比如数组本身已经有序，且每次选择的基准元素都是最值时）时间复杂度会退化为 $O(n^2)$。不过它是一种原地排序算法（不需要额外的大量辅助空间，只需要常数级别的额外空间），并且在实际应用中，通过合理选择基准元素等优化手段，通常能有很好的排序效率。 


