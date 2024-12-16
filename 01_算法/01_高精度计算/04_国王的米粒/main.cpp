#include <iostream>
#include <cmath>

using namespace std;

// 计算国王的米粒总数
long long calculateRice() {
    long long sum = 0;
    for (int i = 0; i < 64; i++) {
        sum += static_cast<long long>(pow(2, i));
    }
    return sum;
}

int main() {
    long long totalRice = calculateRice();
    cout << "国王的米粒总数为: " << totalRice << " 粒" << endl;
    return 0;
}