以下是一个常见的“苹果和虫子”问题案例及C++ 实现。

### 问题描述
假设有\(n\)个苹果，每个苹果上有\(m\)条虫子，现在有\(k\)个苹果被虫子咬了，问还剩下多少条虫子在没被咬的苹果上？

### 代码实现
```cpp
#include <iostream>

int main() {
    int n, m, k;
    std::cout << "请输入苹果的总数 n: ";
    std::cin >> n;
    std::cout << "请输入每个苹果上虫子的数量 m: ";
    std::cin >> m;
    std::cout << "请输入被虫子咬的苹果数量 k: ";
    std::cin >> k;

    if (k > n) {
        std::cout << "被虫子咬的苹果数量不能大于苹果的总数。" << std::endl;
        return 1;
    }

    int remainingApples = n - k;
    int remainingWorms = remainingApples * m;
    std::cout << "没被咬的苹果上还剩下 " << remainingWorms << " 条虫子。" << std::endl;

    return 0;
}
```

### 代码说明
1. **变量声明**：声明了三个 `int` 类型的变量 `n`、`m` 和 `k`，分别用于存储苹果的总数、每个苹果上虫子的数量以及被虫子咬的苹果数量。
2. **输入获取**：通过 `std::cout` 提示用户输入相应的值，并使用 `std::cin` 获取用户输入。
3. **输入验证**：检查被虫子咬的苹果数量 `k` 是否大于苹果的总数 `n`，如果是，则输出错误信息并结束程序。
4. **计算结果**：计算没被咬的苹果数量 `remainingApples`，即 `n - k`。然后计算没被咬的苹果上虫子的总数 `remainingWorms`，即 `remainingApples * m`。
5. **结果输出**：通过 `std::cout` 输出没被咬的苹果上剩下虫子的数量。

你可以根据实际问题对上述代码进行调整和修改。如果问题描述与你所想的不一致，请提供更多细节，以便我给出更准确的解答。