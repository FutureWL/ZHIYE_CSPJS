#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 区间结构体，包含起始时间和结束时间
struct Interval {
    int start;
    int end;
};

// 比较函数，用于按照区间结束时间从小到大排序
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

// 贪心算法实现区间调度
int intervalScheduling(vector<Interval>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    // 先按照区间结束时间对区间进行排序
    sort(intervals.begin(), intervals.end(), compareIntervals);
    int count = 1;
    int lastEnd = intervals[0].end;
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].start >= lastEnd) {
            count++;
            lastEnd = intervals[i].end;
        }
    }
    return count;
}

int main() {
    vector<Interval> intervals = {
        {1, 4},
        {2, 5},
        {3, 6},
        {4, 7},
        {5, 8},
        {6, 9},
        {7, 10},
        {8, 11},
        {9, 12},
        {10, 13},
        {11, 14}
    };
    int maxCount = intervalScheduling(intervals);
    cout << "最多可选择的互不重叠区间数量为: " << maxCount << endl;
    return 0;
}
