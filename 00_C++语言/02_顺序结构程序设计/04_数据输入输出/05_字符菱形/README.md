下面是一个用C++ 打印字符菱形的案例，程序会根据用户输入的字符，打印出一个由该字符组成的菱形。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    char ch;
    std::cout << "请输入一个字符: ";
    std::cin >> ch;

    int size = 5;  // 这里假设菱形的高度（奇数），可以根据需要修改
    for (int i = 1; i <= size; i += 2) {
        // 打印空格
        std::cout << std::setw((size - i) / 2 + 1);
        // 打印字符
        for (int j = 0; j < i; j++) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    for (int i = size - 2; i >= 1; i -= 2) {
        // 打印空格
        std::cout << std::setw((size - i) / 2 + 1);
        // 打印字符
        for (int j = 0; j < i; j++) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    return 0;
}
```

在这个程序中：
1. 首先，程序提示用户输入一个字符，这个字符将用于组成菱形。
2. 定义了菱形的大小 `size`，这里设置为5，你可以修改这个值来改变菱形的大小。注意，`size` 应为奇数，以确保菱形的对称性。
3. 第一个 `for` 循环用于打印菱形的上半部分。在每次迭代中，首先使用 `std::setw` 函数打印一定数量的空格，使字符能够居中显示。然后，使用内层 `for` 循环打印当前行的字符。
4. 第二个 `for` 循环用于打印菱形的下半部分，逻辑与上半部分类似，只是行数递减。

这样，程序就能根据用户输入的字符打印出一个菱形。