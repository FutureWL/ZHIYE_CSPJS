假设邮寄包裹的邮资计算规则如下：

- 重量 `w` 小于等于 1000 克时，邮资为 8 元。
- 重量 `w` 大于 1000 克，小于等于 2000 克时，邮资为 12 元。
- 重量 `w` 大于 2000 克，小于等于 3000 克时，邮资为 18 元。
- 重量 `w` 大于 3000 克时，每增加 1000 克（不足 1000 克按 1000 克计算），邮资增加 5 元。

以下是使用 `switch` 语句实现计算邮资的 C++ 代码：

```cpp
#include <iostream>

int main() {
    int weight;
    std::cout << "请输入包裹重量（单位：克）：";
    std::cin >> weight;

    if (weight <= 0) {
        std::cout << "重量不能为负数或零。" << std::endl;
        return 1;
    }

    int baseWeight = 1000;
    int basePrice = 8;
    int additionalPrice = 5;

    int interval = (weight - 1) / 1000;
    int postage;

    switch (interval) {
    case 0:
        postage = basePrice;
        break;
    case 1:
        postage = 12;
        break;
    case 2:
        postage = 18;
        break;
    default:
        postage = basePrice + additionalPrice * (interval - 1);
        break;
    }

    std::cout << "邮资为：" << postage << " 元" << std::endl;

    return 0;
}
```

### 代码说明：
1. **变量声明**：
    - `weight` 用于存储用户输入的包裹重量。
    - `baseWeight` 表示基础重量单位，这里是 1000 克。
    - `basePrice` 是重量在 1000 克及以内的基础邮资。
    - `additionalPrice` 是超过 3000 克后每增加 1000 克所需增加的邮资。
    - `interval` 用于确定重量处于哪个区间。
    - `postage` 用于存储计算出的邮资。

2. **输入获取与验证**：
    - 使用 `std::cout` 提示用户输入包裹重量，并通过 `std::cin` 获取输入值。
    - 检查输入的重量是否为负数或零，如果是则输出错误信息并结束程序。

3. **计算区间**：
    - `(weight - 1) / 1000` 用于计算重量处于哪个 1000 克的区间。例如，重量为 1000 克时，`(1000 - 1) / 1000 = 0`；重量为 1001 克时，`(1001 - 1) / 1000 = 1`。

4. **`switch` 语句计算邮资**：
    - `case 0` 对应重量小于等于 1000 克的情况，邮资为基础价格 `basePrice`。
    - `case 1` 对应重量大于 1000 克，小于等于 2000 克的情况，邮资为 12 元。
    - `case 2` 对应重量大于 2000 克，小于等于 3000 克的情况，邮资为 18 元。
    - `default` 对应重量大于 3000 克的情况，邮资为基础价格加上超出部分按每 1000 克增加的价格。

5. **结果输出**：
    - 使用 `std::cout` 输出计算出的邮资。