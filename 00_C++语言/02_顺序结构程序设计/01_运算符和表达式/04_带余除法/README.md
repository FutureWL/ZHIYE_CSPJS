以下是几种在 C++ 中实现带余除法的示例代码，涵盖了不同的输入获取方式以及应用场景，供你参考：

### 一、从控制台获取用户输入的被除数和除数来进行带余除法（交互式输入）

```cpp
#include <iostream>
using namespace std;

int main() {
    int dividend, divisor;
    // 提示用户输入被除数
    cout << "请输入被除数：";
    cin >> dividend;
    // 提示用户输入除数
    cout << "请输入除数：";
    cin >> divisor;

    if (divisor == 0) {
        // 检查除数是否为0，若为0则输出错误提示并结束程序
        cout << "除数不能为0，请重新输入合法的除数。" << endl;
        return -1;
    }

    int quotient = dividend / divisor;  // 计算商
    int remainder = dividend % divisor;  // 计算余数

    cout << dividend << "除以" << divisor << "的商是：" << quotient << endl;
    cout << dividend << "除以" << divisor << "的余数是：" << remainder << endl;

    return 0;
}
```

在上述代码中：

- 首先通过 `#include <iostream>` 引入输入输出流相关头文件，以便使用 `cout` 输出提示信息以及最终结果，使用 `cin` 从键盘接收用户输入的整数。
- 在 `main` 函数里定义了两个整型变量 `dividend`（被除数）和 `divisor`（除数），用于存储用户输入的值。
- 接着分别提示用户输入被除数和除数，并通过 `cin` 获取相应输入存储到对应的变量中。同时，对除数是否为 `0` 进行判断，因为除数不能为 `0`，若为 `0` 则输出错误提示并结束程序。
- 然后使用 `/` 运算符计算出商（`quotient`），使用 `%` 运算符计算出余数（`remainder`）。在 C++ 中，`/` 用于整数除法（得到的是商的整数部分），`%` 运算符用于获取两数相除的余数。
- 最后通过 `cout` 输出语句分别展示被除数除以除数得到的商和余数。

### 二、从文件中读取被除数和除数来进行带余除法（适用于批量数据处理等情况）

假设你有一个名为 `input.txt` 的文本文件，文件中每行包含两个用空格隔开的整数，分别对应被除数和除数，示例代码如下：

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
        int dividend, divisor;
        stringstream ss(line);
        // 从字符串流中解析出两个整数
        ss >> dividend >> divisor;

        if (divisor == 0) {
            // 检查当前行的除数是否为0，若为0则输出错误提示，跳过该行继续下一行处理
            cout << "文件中该行数据除数不能为0，请检查数据，跳过该行处理。" << endl;
            continue;
        }

        int quotient = dividend / divisor;
        int remainder = dividend % divisor;

        cout << dividend << "除以" << divisor << "的商是：" << quotient << endl;
        cout << dividend << "除以" << divisor << "的余数是：" << remainder << endl;
    }
    inputFile.close();  // 关闭文件

    return 0;
}
```

这段代码的实现逻辑如下：

- 引入了三个头文件，`iostream` 用于常规的输入输出操作；`fstream` 用于文件输入输出流的操作，实现文件的打开与读取；`sstream` 用于对字符串进行流操作，方便从读取的文本行中解析出整数。
- 在 `main` 函数中，首先尝试打开 `input.txt` 文件，如果打开失败（通过 `if (!inputFile)` 判断），则输出错误提示信息并终止程序。
- 通过 `while` 循环结合 `getline` 函数逐行读取文件内容，每次把读取到的一行存到字符串变量 `line` 中。
- 针对每一行内容，使用 `stringstream` 将其转换为流，从中解析出两个整数 `dividend`（被除数）和 `divisor`（除数）。
- 对解析出的 `divisor` 值进行判断，若其为 `0`，则输出相应错误提示，并使用 `continue` 跳过该行数据的后续处理，继续读取下一行数据。
- 当 `divisor` 不为 `0` 时，分别使用 `/` 运算符计算商，`%` 运算符计算余数，并通过 `cout` 输出语句展示该行数据对应的商和余数。
- 最后在所有行数据处理完后，关闭打开的文件。

### 三、直接在代码中给定被除数和除数进行带余除法（常用于测试等场景）

```cpp
#include <iostream>
using namespace std;

int main() {
    int dividend = 17;
    int divisor = 5;

    int quotient = dividend / divisor;
    int remainder = dividend % divisor;

    cout << dividend << "除以" << divisor << "的商是：" << quotient << endl;
    cout << dividend << "除以" << divisor << "的余数是：" << remainder << endl;

    return 0;
}
```

在这个示例中，直接在代码里给 `dividend`（被除数）和 `divisor`（除数）赋予具体的数值，然后分别使用 `/` 和 `%` 运算符计算出商和余数，并通过 `cout` 输出语句展示结果，这种方式常用于简单的代码功能测试或者已知具体数值进行运算的情况。

希望这些示例能帮助你理解和运用 C++ 中的带余除法，你可以根据实际需求对代码进行修改和拓展。 


