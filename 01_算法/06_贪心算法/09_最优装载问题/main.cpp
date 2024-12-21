#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心算法实现最优装载
int optimalLoading(int C, vector<int>& weights) {
    if (weights.empty()) {
        return 0;
    }
    // 按照货物重量从小到大排序
    sort(weights.begin(), weights.end());
    int count = 0;
    int currentWeight = 0;
    for (int weight : weights) {
        if (currentWeight + weight <= C) {
            currentWeight += weight;
            count++;
        }
        else {
            break;
        }
    }
    return count;
}

int main() {
    int C = 10;
    vector<int> weights = { 1, 2, 3, 4, 5 };
    int maxCount = optimalLoading(C, weights);
    cout << "最多能装载的货物数量为: " << maxCount << endl;
    return 0;
}