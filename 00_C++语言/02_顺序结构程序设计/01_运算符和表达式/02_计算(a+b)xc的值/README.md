以下是几种在C++中计算 `(a + b) × c` 值的示例代码，分别对应不同的输入获取方式以及应用场景，你可以根据实际情况选用。

### 一、从控制台获取用户输入的 `a`、`b`、`c` 值来计算（基本的交互式输入）

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    // 提示用户输入三个整数
    cout << "请输入整数 a 的值：";
    cin >> a;
    cout << "请输入整数 b 的值：";
    cin >> b;
    cout << "请输入整数 c 的值：";
    cin >> c;

    int result = (a + b) * c;
    // 输出计算结果
    cout << "表达式 (a + b) * c 的值为：" << result << endl;

    return 0;
}
```

在这段代码中：

- 首先引入 `iostream` 头文件，用于实现标准输入输出功能，通过 `cout` 输出提示信息以及最终的计算结果，使用 `cin` 从键盘接收用户输入的整数。
- 在 `main` 函数里，定义了三个整型变量 `a`、`b`、`c`，用于存储用户即将输入的数值。
- 接着分三步，依次提示用户输入 `a`、`b`、`c` 的值，并通过 `cin` 语句获取相应的输入，将其存储到对应的变量中。
- 然后按照表达式 `(a + b) × c` 的运算顺序，先计算括号内 `a + b` 的和，再将这个和与 `c` 相乘，把得到的结果存储在变量 `result` 中。
- 最后通过 `cout` 输出语句，向用户展示计算得到的表达式的值。

### 二、从文件中读取 `a`、`b`、`c` 值来计算（适用于批量数据处理等情况）

假设你有一个名为 `input.txt` 的文本文件，文件中每行包含三个用空格隔开的整数，分别对应 `a`、`b`、`c` 的值，示例代码如下：

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
        int a, b, c;
        stringstream ss(line);
        // 从字符串流中解析出三个整数
        ss >> a >> b >> c;

        int result = (a + b) * c;
        // 输出当前行对应的计算结果
        cout << "表达式 (a + b) * c 的值为：" << result << endl;
    }
    inputFile.close();  // 关闭文件

    return 0;
}
```

代码实现逻辑如下：

- 引入了三个头文件，`iostream` 用于常规的输入输出操作；`fstream` 用于文件输入输出流的操作，使得可以打开和读取文件；`sstream` 用于对字符串进行流操作，方便从读取的文本行中解析出整数。
- 在 `main` 函数中，先尝试打开 `input.txt` 文件，如果打开失败（通过 `if (!inputFile)` 判断），则输出错误提示信息并终止程序。
- 通过 `while` 循环结合 `getline` 函数逐行读取文件内容，每次把读取到的一行内容存到字符串变量 `line` 中。
- 针对每一行内容，使用 `stringstream` 将其转换为流，从中解析出三个整数 `a`、`b`、`c`。
- 之后按照表达式 `(a + b) × c` 的运算顺序进行计算，将结果存到变量 `result` 中，并通过 `cout` 输出这一行数据对应的计算结果。
- 最后在所有行数据都处理完后，关闭打开的文件。

### 三、直接在代码中给定 `a`、`b`、`c` 值进行计算（适用于测试等场景）

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 2;
    int b = 3;
    int c = 4;

    int result = (a + b) * c;
    // 输出计算结果
    cout << "表达式 (a + b) * c 的值为：" << result << endl;

    return 0;
}
```

在这个示例中，直接在代码里给 `a`、`b`、`c` 这三个整型变量赋予具体的数值，然后按照数学运算顺序计算 `(a + b) × c` 的值，并通过 `cout` 输出语句展示计算结果，常用于简单的代码功能测试或者已知具体数值进行运算的情况。

希望这些示例对你理解和实现相关功能有所帮助，你可以根据实际需求对代码进行修改和拓展。 