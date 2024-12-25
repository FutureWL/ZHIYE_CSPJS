以下是一个展示整型与布尔型相互转换的C++ 项目示例，包含详细的注释说明：

```cpp
#include <iostream>

// 函数：将整型转换为布尔型
bool intToBool(int num) {
    return num!= 0;
}

// 函数：将布尔型转换为整型
int boolToInt(bool b) {
    return b? 1 : 0;
}

int main() {
    // 整型转换为布尔型
    int intValue1 = 0;
    int intValue2 = 5;
    int intValue3 = -3;

    bool boolValue1 = intToBool(intValue1);
    bool boolValue2 = intToBool(intValue2);
    bool boolValue3 = intToBool(intValue3);

    std::cout << intValue1 << " 转换为布尔型是: " << (boolValue1? "true" : "false") << std::endl;
    std::cout << intValue2 << " 转换为布尔型是: " << (boolValue2? "true" : "false") << std::endl;
    std::cout << intValue3 << " 转换为布尔型是: " << (boolValue3? "true" : "false") << std::endl;

    // 布尔型转换为整型
    bool boolValue4 = true;
    bool boolValue5 = false;

    int intValue4 = boolToInt(boolValue4);
    int intValue5 = boolToInt(boolValue5);

    std::cout << "true 转换为整型是: " << intValue4 << std::endl;
    std::cout << "false 转换为整型是: " << intValue5 << std::endl;

    return 0;
}
```

### 代码说明
1. **`intToBool` 函数**：
    - 该函数接受一个整数参数 `num`。
    - 通过判断 `num` 是否不等于0，返回相应的布尔值。如果 `num` 是非零值，返回 `true`；如果 `num` 是0，返回 `false`。
2. **`boolToInt` 函数**：
    - 该函数接受一个布尔值参数 `b`。
    - 使用条件运算符（`? :`），如果 `b` 为 `true`，返回1；如果 `b` 为 `false`，返回0。
3. **`main` 函数**：
    - **整型转布尔型部分**：
      - 定义了三个整型变量 `intValue1`（值为0）、`intValue2`（值为5）和 `intValue3`（值为 - 3）。
      - 调用 `intToBool` 函数将这三个整型值转换为布尔值，并分别存储在 `boolValue1`、`boolValue2` 和 `boolValue3` 中。
      - 使用 `std::cout` 输出每个整型值转换后的布尔值。
    - **布尔型转整型部分**：
      - 定义了两个布尔型变量 `boolValue4`（值为 `true`）和 `boolValue5`（值为 `false`）。
      - 调用 `boolToInt` 函数将这两个布尔值转换为整型值，并分别存储在 `intValue4` 和 `intValue5` 中。
      - 使用 `std::cout` 输出每个布尔值转换后的整型值。

通过这个项目，可以清晰地看到C++ 中整型与布尔型之间的转换规则及实现方式。 