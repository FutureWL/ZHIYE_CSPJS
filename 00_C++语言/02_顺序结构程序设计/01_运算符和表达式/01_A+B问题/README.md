以下是几种用 C++ 解决 A + B 问题的常见示例，分别对应不同的输入场景，你可以参考一下：

### 一、从标准输入读取两个整数并计算输出它们的和（控制台输入）

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    // 提示用户输入两个整数
    cout << "请输入两个整数：" << endl;
    // 从标准输入读取两个整数
    cin >> a >> b;
    // 计算并输出两数之和
    cout << "两数之和为：" << a + b << endl;

    return 0;
}
```

在这个示例中：

- 首先通过 `#include <iostream>` 引入输入输出流相关的头文件，使得可以使用 `cout`（用于输出提示信息和结果）以及 `cin`（用于接收用户从键盘输入的数据）。
- 在 `main` 函数里，定义了两个整型变量 `a` 和 `b`，用来存储用户输入的两个整数。
- 使用 `cout` 输出提示语句，告知用户需要输入两个整数。
- 接着通过 `cin` 从标准输入（通常就是键盘输入）依次读取两个整数，并分别存储到 `a` 和 `b` 中。
- 最后再用 `cout` 输出语句，输出 `a` 和 `b` 这两个整数相加后的结果。

### 二、从文件中读取两个整数并计算它们的和（文件输入）

假设你有一个名为 `input.txt` 的文本文件，文件中每行有两个用空格隔开的整数，示例代码如下：

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream inputFile("input.txt");  // 打开名为input.txt的文件，用于读取
    if (!inputFile) {
        cerr << "无法打开文件 input.txt" << endl;
        return -1;
    }
    string line;
    while (getline(inputFile, line)) {  // 逐行读取文件内容
        int a, b;
        stringstream ss(line);
        // 从字符串流中解析出两个整数
        ss >> a >> b;
        // 计算并输出两数之和
        cout << "两数之和为：" << a + b << endl;
    }
    inputFile.close();  // 关闭文件

    return 0;
}
```

这段代码的实现过程如下：

- 引入了三个头文件，`#include <iostream>` 用于常规的输入输出操作，`#include <fstream>` 用于文件输入输出流的操作，`#include <sstream>` 用于对字符串进行流操作（方便从读取的文本行中解析出整数）。
- 在 `main` 函数中，首先尝试打开名为 `input.txt` 的文件，如果文件打开失败（`if (!inputFile)` 判断），则输出错误提示信息并结束程序。
- 通过 `while` 循环和 `getline` 函数逐行读取文件内容，每次读取一行存到字符串变量 `line` 中。
- 对于读取到的每一行内容，利用 `stringstream` 将字符串转换为流，再从中解析出两个整数 `a` 和 `b`，最后计算并输出它们的和。
- 在循环结束后，关闭打开的文件。

### 三、给定两个整数直接计算它们的和（直接赋值计算）

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 3;
    // 直接计算并输出两数之和
    cout << "两数之和为：" << a + b << endl;

    return 0;
}
```

在这种情况下，直接在代码中给两个整型变量 `a` 和 `b` 赋予具体的值，然后通过 `cout` 输出它们相加后的结果，这种方式常用于测试或者已知具体数值的简单运算场景。

这些示例展示了在 C++ 中解决 A + B 问题的不同方式，你可以根据实际需求（如输入来源、使用场景等）来选择合适的代码实现方式。