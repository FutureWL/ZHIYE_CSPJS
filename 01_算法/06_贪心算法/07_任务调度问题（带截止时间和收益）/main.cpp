#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 任务结构体，包含任务编号、截止时间和收益
struct Task {
    int id;
    int deadline;
    int profit;
};

// 比较函数，用于按照收益从大到小对任务排序
bool compareTasks(const Task& a, const Task& b) {
    return a.profit > b.profit;
}

// 贪心算法实现任务调度
int jobScheduling(vector<Task>& tasks) {
    if (tasks.empty()) {
        return 0;
    }
    // 先按照收益对任务进行排序
    sort(tasks.begin(), tasks.end(), compareTasks);
    int maxDeadline = 0;
    for (Task task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }
    vector<bool> slots(maxDeadline, false);
    int totalProfit = 0;
    for (Task task : tasks) {
        for (int i = task.deadline - 1; i >= 0; i--) {
            if (!slots[i]) {
                slots[i] = true;
                totalProfit += task.profit;
                break;
            }
        }
    }
    return totalProfit;
}

int main() {
    vector<Task> tasks = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    int maxProfit = jobScheduling(tasks);
    cout << "最大总收益为: " << maxProfit << endl;
    return 0;
}