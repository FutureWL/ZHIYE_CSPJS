#include <iostream>
#include <vector>
using namespace std;

// 希尔排序函数
void shellSort(vector<int>& arr) {
    // 确定初始间隔（gap）：
    // 首先，我们选择一个初始的间隔 gap，通常初始值取数组长度的一半（n / 2），
    // 然后在每次循环中不断缩小这个间隔（gap /= 2），直到 gap 变为 0 为止。
    // 这个间隔序列控制着元素比较和交换的跨度，它使得排序过程逐步逼近最终有序的状态，
    // 就好像是先对比较 “粗糙” 的子序列进行排序，再逐渐细化排序的粒度。
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        /*
        * 对每个子序列进行插入排序：
        * 对于每一个确定的 gap 值，我们从索引为 gap 的元素开始遍历数组（for (int i = gap; i < n; i++)），
        * 把当前元素 arr[i] 暂存到 temp 变量中，然后进入内层循环，
        * 内层循环用于对以 gap 为间隔划分的子序列进行插入排序。
        * 它会将 temp 与前面间隔为 gap 的元素依次比较（arr[j - gap] > temp），
        * 如果前面的元素大，就把它往后移（arr[j] = arr[j - gap];），
        * 一直找到合适的位置（即前面的元素不大于 temp 了），再把 temp 插入到该位置（arr[j] = temp;）。
        */
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = { 12, 34, 54, 2, 24, 65, 77, 31 };
    cout << "排序前的数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "排序后的数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}