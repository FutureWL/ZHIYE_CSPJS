#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 活动结构体，包含开始时间和结束时间
struct Activity {
    int start;
    int end;
};

// 比较函数，用于按照活动结束时间排序，使得结束时间早的活动排在前面
bool compareActivities(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

// 贪心算法实现活动安排
int activitySelection(vector<Activity>& activities) {
    if (activities.empty()) {
        return 0;
    }
    // 先按照活动结束时间对活动进行排序
    sort(activities.begin(), activities.end(), compareActivities);
    int count = 1;
    int lastEnd = activities[0].end;
    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}

int main() {
    vector<Activity> activities = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 13},
        {12, 14}
    };
    int selectedCount = activitySelection(activities);
    cout << "最多可安排的活动数量为: " << selectedCount << endl;
    return 0;
}