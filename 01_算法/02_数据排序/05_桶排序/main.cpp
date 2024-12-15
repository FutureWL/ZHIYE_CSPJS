#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 桶排序函数
void bucketSort(vector<int>& arr, int bucketSize = 5) {
    if (arr.size() == 0) {
        return;
    }

    // 找到数组中的最大值和最小值
    int minValue = arr[0], maxValue = arr[0];
    for (int num : arr) {
        minValue = min(minValue, num);
        maxValue = max(maxValue, num);
    }

    // 计算桶的数量
    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);

    // 将元素分配到各个桶中
    for (int num : arr) {
        int bucketIndex = (num - minValue) / bucketSize;
        buckets[bucketIndex].push_back(num);
    }

    // 对每个桶内的元素进行排序（这里使用内置的排序函数，一般是快速排序等高效排序算法）
    int index = 0;
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        for (int element : bucket) {
            arr[index++] = element;
        }
    }
}

int main() {
    // 待排序数列
    vector<int> numbers = { 42, 19, 3, 48, 15, 27 };
    // 桶排序数列
    bucketSort(numbers);
    // 输出排序好的数列
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}