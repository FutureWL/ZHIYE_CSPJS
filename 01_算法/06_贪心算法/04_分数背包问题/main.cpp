#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 物品结构体，包含重量和价值
struct Item {
    int weight;
    int value;
};

// 计算每个物品的单位价值（价值/重量）
double unitValue(const Item& item) {
    return static_cast<double>(item.value) / item.weight;
}

// 比较函数，用于按照单位价值排序，使得单位价值高的物品排在前面
bool compareItems(const Item& a, const Item& b) {
    return unitValue(a) > unitValue(b);
}

// 贪心算法实现分数背包
double fractionalKnapsack(vector<Item>& items, int capacity) {
    if (items.empty()) {
        return 0;
    }
    // 先按照单位价值对物品进行排序
    sort(items.begin(), items.end(), compareItems);
    double totalValue = 0;
    for (size_t i = 0; i < items.size(); i++) {
        if (capacity >= items[i].weight) {
            // 如果背包容量大于等于物品重量，直接装入整个物品
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            // 如果背包容量小于物品重量，装入部分物品
            totalValue += unitValue(items[i]) * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int capacity = 50;
    double maxValue = fractionalKnapsack(items, capacity);
    cout << "背包能装入的最大价值为: " << maxValue << endl;
    return 0;
}