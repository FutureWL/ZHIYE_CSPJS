#include <iostream>
#include <vector>

using namespace std;

// 使用动态规划（自底向上的方式）计算斐波那契数列的第n项
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10;
    int result = fibonacci(n);
    cout << "斐波那契数列第 " << n << " 项的值为: " << result << endl;
    return 0;
}