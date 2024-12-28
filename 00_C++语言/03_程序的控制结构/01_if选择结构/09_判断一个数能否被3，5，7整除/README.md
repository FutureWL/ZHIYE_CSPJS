以下是一个用C++ 判断一个数是否能同时被3、5和7整除的案例：

```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "请输入一个整数: ";
    std::cin >> number;

    if (number % 3 == 0 && number % 5 == 0 && number % 7 == 0) {
        std::cout << number << " 能同时被 3、5 和 7 整除。" << std::endl;
    } else {
        std::cout << number << " 不能同时被 3、5 和 7 整除。" << std::endl;
    }

    return 0;
}
```

### 代码说明
1. **变量声明**：
   - 声明一个整型变量 `number`，用于存储用户输入的整数。
2. **输入获取**：
   - 使用 `std::cout` 输出提示信息，要求用户输入一个整数。然后通过 `std::cin` 将用户输入的值读入 `number` 变量中。
3. **整除判断**：
   - 使用 `if` 语句和逻辑与运算符 `&&` 来判断 `number` 是否同时满足被3、5和7整除的条件。即 `number % 3 == 0 && number % 5 == 0 && number % 7 == 0`。
   - 如果满足条件，输出该数能同时被3、5和7整除的信息；否则，输出不能同时被整除的信息。

你也可以将这个判断逻辑封装成一个函数，如下所示：

```cpp
#include <iostream>

bool isDivisible(int num) {
    return num % 3 == 0 && num % 5 == 0 && num % 7 == 0;
}

int main() {
    int number;
    std::cout << "请输入一个整数: ";
    std::cin >> number;

    if (isDivisible(number)) {
        std::cout << number << " 能同时被 3、5 和 7 整除。" << std::endl;
    } else {
        std::cout << number << " 不能同时被 3、5 和 7 整除。" << std::endl;
    }

    return 0;
}
```

在这个版本中，`isDivisible` 函数接受一个整数参数 `num`，并返回该数是否能同时被3、5和7整除的布尔值。`main` 函数通过调用这个函数来进行判断并输出结果，这样代码结构更加清晰，并且方便在其他地方复用这个判断逻辑。