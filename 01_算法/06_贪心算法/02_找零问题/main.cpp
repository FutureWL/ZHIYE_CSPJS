#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 货币面额
vector<int> denominations = { 20, 10, 5, 1 };

// 贪心算法实现找零
vector<int> makeChange(int amount) {
    vector<int> result(denominations.size(), 0);
    for (size_t i = 0; i < denominations.size(); i++) {
        result[i] = amount / denominations[i];
        amount %= denominations[i];
    }
    return result;
}

int main() {
    int amount = 63;
    vector<int> change = makeChange(amount);
    cout << "凑出 " << amount << " 元需要的货币数量如下：" << endl;
    for (size_t i = 0; i < denominations.size(); i++) {
        cout << denominations[i] << " 元：" << change[i] << " 张" << endl;
    }
    return 0;
}