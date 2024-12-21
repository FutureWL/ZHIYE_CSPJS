#include <iostream>
#include <vector>

using namespace std;

// 物品结构体，包含重量和价值
struct Item {
    int weight;
    int value;
};

// 使用动态规划解决0-1背包问题
int knapsack(vector<Item>& items, int W) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<Item> items = {
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6}
    };
    int W = 8;
    int result = knapsack(items, W);
    cout << "背包能装入的最大价值为: " << result << endl;
    return 0;
}