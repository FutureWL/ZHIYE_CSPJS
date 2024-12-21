以下是几种在C++中涉及温度表达转化且与数组相关的示例代码，分别展示了不同的应用场景，比如将摄氏温度与华氏温度相互转换，并使用数组来存储多个温度值进行批量转换等情况，你可以根据实际需求参考选用。

### 一、将单个摄氏温度值转换为华氏温度，并使用数组存储转换结果（简单的单次转换及存储示例）

```cpp
#include <iostream>
using namespace std;

int main() {
    double celsius;  // 用于存储摄氏温度值
    cout << "请输入摄氏温度：";
    cin >> celsius;

    double fahrenheit = celsius * 9 / 5 + 32;  // 摄氏温度转华氏温度的公式

    double resultArray[1];  // 定义数组来存储转换后的结果，这里只存一个值所以大小为1
    resultArray[0] = fahrenheit;

    cout << celsius << "摄氏度对应的华氏温度是：" << resultArray[0] << "华氏度" << endl;

    return 0;
}
```

在上述代码中：

- 首先通过 `cout` 提示用户输入摄氏温度值，然后使用 `cin` 接收用户输入并存储到变量 `celsius` 中。
- 按照摄氏温度转华氏温度的公式 `F = C × 9 / 5 + 32`（其中 `F` 表示华氏温度，`C` 表示摄氏温度），计算出对应的华氏温度值并存储在变量 `fahrenheit` 中。
- 定义一个大小为 `1` 的 `double` 类型数组 `resultArray`，用于存储转换后的华氏温度结果，将计算得到的 `fahrenheit` 值赋给 `resultArray[0]`。
- 最后通过 `cout` 输出语句展示转换后的温度结果，告知用户输入的摄氏温度对应的华氏温度是多少。

### 二、批量将多个摄氏温度值转换为华氏温度，用数组存储输入和输出温度（适用于批量处理温度数据的场景）

```cpp
#include <iostream>
using namespace std;

int main() {
    const int numTemperatures = 5;  // 定义要转换的温度数量，可根据实际需求修改
    double celsiusArray[numTemperatures];  // 存储输入的摄氏温度值的数组
    double fahrenheitArray[numTemperatures];  // 存储转换后的华氏温度值的数组

    cout << "请依次输入 " << numTemperatures << " 个摄氏温度值：" << endl;
    for (int i = 0; i < numTemperatures; ++i) {
        cin >> celsiusArray[i];
        fahrenheitArray[i] = celsiusArray[i] * 9 / 5 + 32;  // 逐个进行温度转换并存储结果
    }

    cout << "摄氏温度\t华氏温度" << endl;
    for (int i = 0; i < numTemperatures; ++i) {
        cout << celsiusArray[i] << "\t\t" << fahrenheitArray[i] << endl;
    }

    return 0;
}
```

在这段代码里：

- 先定义了一个常量 `numTemperatures`，用于表示要进行温度转换的数量，这里设定为 `5`，你可以按需更改这个值来处理不同数量的温度数据。
- 接着定义了两个 `double` 类型的数组 `celsiusArray` 和 `fahrenheitArray`，分别用于存储输入的摄氏温度值和转换后的华氏温度值，它们的大小都由 `numTemperatures` 确定。
- 通过一个 `for` 循环提示用户依次输入 `numTemperatures` 个摄氏温度值，并将这些值存储到 `celsiusArray` 数组对应的元素中，同时按照温度转换公式计算出每个摄氏温度对应的华氏温度值，存储到 `fahrenheitArray` 数组相应的元素中。
- 再使用另一个 `for` 循环，以表格形式输出输入的摄氏温度值和对应的华氏温度值，方便查看转换结果，每个温度值占一行，用制表符 `\t` 来进行一定的对齐，使输出更整齐。

### 三、将华氏温度转换为摄氏温度，通过函数实现转换逻辑并使用数组处理多个温度值（提高代码模块化程度及可复用性的示例）

```cpp
#include <iostream>
using namespace std;

// 函数用于将华氏温度转换为摄氏温度
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    const int numTemperatures = 3;  // 定义要转换的温度数量，可调整
    double fahrenheitArray[numTemperatures];  // 存储输入的华氏温度值的数组
    double celsiusArray[numTemperatures];  // 存储转换后的摄氏温度值的数组

    cout << "请依次输入 " << numTemperatures << " 个华氏温度值：" << endl;
    for (int i = 0; i < numTemperatures; ++i) {
        cin >> fahrenheitArray[i];
        celsiusArray[i] = fahrenheitToCelsius(fahrenheitArray[i]);  // 调用函数进行转换并存储结果
    }

    cout << "华氏温度\t摄氏温度" << endl;
    for (int i = 0; i < numTemperatures; ++i) {
        cout << fahrenheitArray[i] << "\t\t" << celsiusArray[i] << endl;
    }

    return 0;
}
```

这个示例代码的实现思路如下：

- 首先定义了一个名为 `fahrenheitToCelsius` 的函数，它接收一个 `double` 类型的参数 `fahrenheit`，代表华氏温度值，函数内部按照华氏温度转摄氏温度的公式 `C = (F - 32) × 5 / 9`（其中 `C` 表示摄氏温度，`F` 表示华氏温度）进行计算，并返回转换后的摄氏温度值。这样把温度转换的逻辑封装在函数里，提高了代码的模块化程度，方便在其他地方复用这个转换功能。
- 在 `main` 函数中，同样先定义了常量 `numTemperatures` 来确定要转换的温度数量，然后定义两个数组 `fahrenheitArray` 和 `celsiusArray`，分别用于存储输入的华氏温度值和转换后的摄氏温度值。
- 通过一个 `for` 循环提示用户输入 `numTemperatures` 个华氏温度值，存储到 `fahrenheitArray` 数组中，并且调用 `fahrenheitToCelsius` 函数将每个华氏温度值转换为摄氏温度值，存储到 `celsiusArray` 数组相应元素中。
- 最后再用一个 `for` 循环以表格形式输出输入的华氏温度值和对应的摄氏温度值，便于查看转换后的结果情况。

希望这些示例能够帮助你理解在C++中如何利用数组来进行温度表达转化相关的操作，你可以根据实际情况对代码进行修改和拓展，比如改变温度数量、添加输入合法性检查等功能。 


