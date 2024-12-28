#include <iostream>
#include <unordered_map>

int main() {
    // 用于记录每种瓶盖的数量
    std::unordered_map<char, int> capCount;
    char cap;

    std::cout << "请输入收集到的瓶盖（按任意非字母键结束输入）：" << std::endl;
    while (std::cin >> cap && std::isalpha(cap)) {
        if (capCount.find(cap) != capCount.end()) {
            capCount[cap]++;
        }
        else {
            capCount[cap] = 1;
        }
    }

    // 假设收集到3个'A'瓶盖和5个'B'瓶盖可以赢大奖
    if (capCount.find('A') != capCount.end() && capCount['A'] >= 3 &&
        capCount.find('B') != capCount.end() && capCount['B'] >= 5) {
        std::cout << "恭喜你，赢得大奖！" << std::endl;
    }
    else {
        std::cout << "很遗憾，未达到赢奖条件。" << std::endl;
    }

    return 0;
}