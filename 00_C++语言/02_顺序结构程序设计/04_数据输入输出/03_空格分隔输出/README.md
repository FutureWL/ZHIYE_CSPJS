1. **简单变量输出用空格分隔**
   - 当你需要输出多个变量，并使用空格分隔时，可以在每次输出变量后添加一个空格字符。
```cpp
#include <iostream>

int main() {
    int num1 = 10;
    double num2 = 3.14;
    char ch = 'A';
    std::cout << num1 << " " << num2 << " " << ch << std::endl;
    return 0;
}
```
   - 在上述代码中，`std::cout`依次输出`num1`、`num2`和`ch`，在每个变量之间添加了一个空格字符`' '`，这样输出的结果就是以空格分隔的。输出结果为：`10 3.14 A`。

2. **数组元素输出用空格分隔**
   - 对于数组元素的输出，同样可以在每次输出元素后添加空格。
```cpp
#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
```
   - 此代码遍历数组`arr`，输出每个元素。在除了最后一个元素之外的每个元素后面添加一个空格，这样数组元素就以空格分隔输出。输出结果为：`1 2 3 4 5`。

3. **使用`<iomanip>`库控制输出格式并空格分隔**
   - `<iomanip>`库提供了一些操纵符，如`setw`，可以设置输出字段的宽度，这在按特定格式用空格分隔输出时很有用。
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num1 = 5;
    int num2 = 123;
    std::cout << std::setw(5) << num1 << std::setw(5) << num2 << std::endl;
    return 0;
}
```
   - `std::setw(5)`设置了每个输出字段的宽度为5个字符。`num1`和`num2`在输出时，如果其自身宽度小于5，会在前面填充空格。输出结果为：`    5  123`，两个数字之间自然形成了空格分隔。

4. **使用`<format>`库（C++20 及以上）控制空格分隔输出**
   - `<format>`库提供了强大的格式化功能。
```cpp
#include <iostream>
#include <format>

int main() {
    int num1 = 7;
    int num2 = 45;
    std::cout << std::format("{:5}{:5}", num1, num2) << std::endl;
    return 0;
}
```
   - 在格式化字符串`"{:5}{:5}"`中，`{:5}`表示该字段宽度为5，不足5个字符时用空格填充。输出结果类似：`    7    45`，两个数字之间通过空格分隔。 