以下是一个简单的C++案例，模拟“收集瓶盖赢大奖”的场景。假设活动规定收集到一定数量特定瓶盖组合可以兑换大奖。

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    // 用于记录每种瓶盖的数量
    std::unordered_map<char, int> capCount;
    char cap;

    std::cout << "请输入收集到的瓶盖（按任意非字母键结束输入）：" << std::endl;
    while (std::cin >> cap && std::isalpha(cap)) {
        if (capCount.find(cap)!= capCount.end()) {
            capCount[cap]++;
        } else {
            capCount[cap] = 1;
        }
    }

    // 假设收集到3个'A'瓶盖和5个'B'瓶盖可以赢大奖
    if (capCount.find('A')!= capCount.end() && capCount['A'] >= 3 &&
        capCount.find('B')!= capCount.end() && capCount['B'] >= 5) {
        std::cout << "恭喜你，赢得大奖！" << std::endl;
    } else {
        std::cout << "很遗憾，未达到赢奖条件。" << std::endl;
    }

    return 0;
}
```

### 代码解释
1. **数据结构**：
    - 使用 `std::unordered_map<char, int>` 来存储不同类型瓶盖及其数量。键是瓶盖的类型（用字符表示），值是该类型瓶盖的数量。
2. **输入部分**：
    - 通过 `while` 循环，不断读取用户输入的瓶盖类型。只要输入的是字母，就会进入循环处理。
    - 如果该瓶盖类型已经在 `capCount` 中存在，则将其数量加一；否则，初始化该瓶盖类型的数量为1。
3. **判断是否赢奖**：
    - 假设赢奖条件是收集到至少3个'A'瓶盖和至少5个'B'瓶盖。
    - 使用 `if` 语句检查 `capCount` 中是否存在'A'和'B'瓶盖，并且它们的数量是否满足赢奖条件。如果满足，输出恭喜信息；否则，输出遗憾信息。

你可以根据实际的赢奖规则修改判断条件部分的代码。例如，如果赢奖规则变为收集到特定数量的多种不同瓶盖，只需相应地调整 `if` 语句中的条件。