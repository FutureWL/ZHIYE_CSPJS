1. **判断单个字符的ASCII值奇偶性**
```cpp
#include <iostream>

int main() {
    char ch;
    std::cout << "请输入一个字符: ";
    std::cin >> ch;
    int asciiValue = static_cast<int>(ch);
    if (asciiValue % 2 == 0) {
        std::cout << "字符 '" << ch << "' 的ASCII值 " << asciiValue << " 是偶数。" << std::endl;
    } else {
        std::cout << "字符 '" << ch << "' 的ASCII值 " << asciiValue << " 是奇数。" << std::endl;
    }
    return 0;
}
```
在上述代码中：
    - 首先声明一个字符变量 `ch`，用于存储用户输入的字符。
    - 使用 `std::cout` 提示用户输入一个字符，并通过 `std::cin` 获取用户输入的字符。
    - 使用 `static_cast<int>(ch)` 将字符 `ch` 转换为对应的ASCII值，存储在 `asciiValue` 变量中。
    - 通过取模运算 `asciiValue % 2` 判断 `asciiValue` 是否能被2整除，根据判断结果输出相应信息。

2. **判断字符串中每个字符的ASCII值奇偶性**
```cpp
#include <iostream>
#include <string>

void checkASCIIParity(const std::string& str) {
    for (char ch : str) {
        int asciiValue = static_cast<int>(ch);
        if (asciiValue % 2 == 0) {
            std::cout << "字符 '" << ch << "' 的ASCII值 " << asciiValue << " 是偶数。" << std::endl;
        } else {
            std::cout << "字符 '" << ch << "' 的ASCII值 " << asciiValue << " 是奇数。" << std::endl;
        }
    }
}

int main() {
    std::string str;
    std::cout << "请输入一个字符串: ";
    std::getline(std::cin, str);
    checkASCIIParity(str);
    return 0;
}
```
在这段代码中：
    - 定义了一个函数 `checkASCIIParity`，该函数接受一个 `std::string` 类型的字符串作为参数。
    - 使用范围 - for 循环遍历字符串中的每个字符 `ch`，将其转换为ASCII值后判断奇偶性，并输出相应信息。
    - 在 `main` 函数中，声明一个 `std::string` 类型的变量 `str`，使用 `std::getline` 函数获取用户输入的字符串，然后调用 `checkASCIIParity` 函数对字符串中的每个字符进行ASCII值奇偶性判断。

3. **根据ASCII值奇偶性进行字符分类**
```cpp
#include <iostream>
#include <string>
#include <vector>

std::vector<char> evenASCIIChars;
std::vector<char> oddASCIIChars;

void classifyByASCIIParity(const std::string& str) {
    for (char ch : str) {
        int asciiValue = static_cast<int>(ch);
        if (asciiValue % 2 == 0) {
            evenASCIIChars.push_back(ch);
        } else {
            oddASCIIChars.push_back(ch);
        }
    }
}

void printCharacterLists() {
    std::cout << "ASCII值为偶数的字符: ";
    for (char ch : evenASCIIChars) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    std::cout << "ASCII值为奇数的字符: ";
    for (char ch : oddASCIIChars) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string str;
    std::cout << "请输入一个字符串: ";
    std::getline(std::cin, str);
    classifyByASCIIParity(str);
    printCharacterLists();
    return 0;
}
```
在这个示例中：
    - 定义了两个 `std::vector<char>` 类型的全局变量 `evenASCIIChars` 和 `oddASCIIChars`，分别用于存储ASCII值为偶数和奇数的字符。
    - `classifyByASCIIParity` 函数遍历输入字符串，根据字符的ASCII值奇偶性将其分别存储到对应的向量中。
    - `printCharacterLists` 函数用于输出两个向量中的字符。
    - 在 `main` 函数中，获取用户输入的字符串，调用 `classifyByASCIIParity` 函数进行分类，然后调用 `printCharacterLists` 函数输出分类结果。