1. **基本判断**
   - 以下是一个简单的C++程序，用于判断一个整数是正数、负数还是零。
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "请输入一个整数: ";
    std::cin >> num;
    if (num > 0) {
        std::cout << num << " 是正数。" << std::endl;
    } else if (num < 0) {
        std::cout << num << " 是负数。" << std::endl;
    } else {
        std::cout << num << " 是零。" << std::endl;
    }
    return 0;
}
```
   - 在上述代码中：
     - 首先声明一个整型变量 `num` 用于存储用户输入的整数。
     - 然后使用 `std::cout` 提示用户输入一个整数，并通过 `std::cin` 获取用户输入的值并存储到 `num` 中。
     - 接着使用 `if - else if - else` 语句进行判断。如果 `num` 大于 0，则输出该数是正数；如果 `num` 小于 0，则输出该数是负数；如果 `num` 等于 0，则输出该数是零。

2. **处理浮点数**
   - 该程序可以处理浮点数的正负判断。
```cpp
#include <iostream>

int main() {
    double num;
    std::cout << "请输入一个浮点数: ";
    std::cin >> num;
    if (num > 0) {
        std::cout << num << " 是正数。" << std::endl;
    } else if (num < 0) {
        std::cout << num << " 是负数。" << std::endl;
    } else {
        std::cout << num << " 是零。" << std::endl;
    }
    return 0;
}
```
   - 这里将变量类型改为 `double`，以处理浮点数输入，判断逻辑与处理整数时相同。

3. **使用函数封装判断逻辑**
   - 可以将判断逻辑封装到一个函数中，使代码结构更清晰，便于复用。
```cpp
#include <iostream>

void checkSign(double num) {
    if (num > 0) {
        std::cout << num << " 是正数。" << std::endl;
    } else if (num < 0) {
        std::cout << num << " 是负数。" << std::endl;
    } else {
        std::cout << num << " 是零。" << std::endl;
    }
}

int main() {
    double num;
    std::cout << "请输入一个数: ";
    std::cin >> num;
    checkSign(num);
    return 0;
}
```
   - 在这个程序中，定义了一个名为 `checkSign` 的函数，该函数接受一个 `double` 类型的参数 `num`，并在函数内部进行正负判断和输出。在 `main` 函数中，获取用户输入的数后调用 `checkSign` 函数进行判断。 