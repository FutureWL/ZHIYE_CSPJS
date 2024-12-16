以下是几个使用C++实现递推算法的示例，展示其在不同问题场景下的应用：

### 示例一：斐波那契数列

斐波那契数列指的是这样一个数列：0、1、1、2、3、5、8、13、21、34……，从第三项开始，每一项都等于前两项之和。

```cpp
#include <iostream>

using namespace std;

// 计算斐波那契数列第n项的函数（使用递推）
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, result;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    cout << "请输入要计算的斐波那契数列的项数: ";
    cin >> n;
    int fib = fibonacci(n);
    cout << "斐波那契数列第" << n << "项的值为: " << fib << endl;
    return 0;
}
```

**代码解释**：
- **`fibonacci` 函数**：首先处理边界情况，当 `n` 为 `0` 时返回 `0`，当 `n` 为 `1` 时返回 `1`。对于 `n` 大于 `1` 的情况，使用三个变量 `a`、`b` 和 `result`，初始化 `a` 为 `0`（代表第 `0` 项），`b` 为 `1`（代表第 `1` 项）。然后通过循环从第 `2` 项开始递推计算，每次把 `a` 和 `b` 的和赋给 `result`，接着更新 `a` 为原来的 `b`，`b` 为新计算出的 `result`，循环结束后，`result` 就是第 `n` 项的值。
- **`main` 函数**：提示用户输入要计算的斐波那契数列的项数 `n`，调用 `fibonacci` 函数计算该项的值，并输出展示给用户。

### 示例二：阶乘计算

阶乘的定义为：对于正整数 `n`，`n! = n * (n - 1) * (n - 2) * … * 2 * 1`，例如 `5! = 5 * 4 * 3 * 2 * 1 = 120`。

```cpp
#include <iostream>

using namespace std;

// 计算n的阶乘的函数（使用递推）
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cout << "请输入要计算阶乘的正整数: ";
    cin >> n;
    int fact = factorial(n);
    cout << n << "的阶乘为: " << fact << endl;
    return 0;
}
```

**代码解释**：
- **`factorial` 函数**：初始化一个变量 `result` 为 `1`，它代表初始的乘积结果（因为 `1! = 1`）。然后通过循环从 `2` 开始到 `n`，每次让 `result` 乘以当前的循环变量 `i`，这样就实现了从 `1` 开始不断乘以后续整数的递推过程，循环结束后，`result` 就是 `n` 的阶乘值。
- **`main` 函数**：提示用户输入要计算阶乘的正整数 `n`，调用 `factorial` 函数计算其阶乘值，并输出展示给用户。

### 示例三：杨辉三角

杨辉三角是一个二项式系数在三角形中的一种几何排列，其特点是每行两端都是 `1`，中间的数等于它上方两数之和。

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

// 计算杨辉三角中指定位置的数值（使用递推）
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

// 打印杨辉三角前n行的函数
void printPascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << setw(6) << binomialCoefficient(i, j);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "请输入要打印的杨辉三角的行数: ";
    cin >> n;
    printPascalTriangle(n);
    return 0;
}
```

**代码解释**：
- **`binomialCoefficient` 函数**：先处理边界情况，当 `k` 为 `0` 或者 `k` 等于 `n` 时（也就是每行的两端元素），返回 `1`。对于其他情况，根据杨辉三角的性质，通过递归调用（这里本质也是一种递推，利用前面计算过的结果来计算当前结果）该函数，返回上一行对应位置的两个数之和，即 `binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k)`。
- **`printPascalTriangle` 函数**：通过两层嵌套的 `for` 循环来控制行数和每行的元素个数，对于每一个位置 `(i, j)`，调用 `binomialCoefficient` 函数来获取对应的杨辉三角中的数值，并通过 `setw` 函数设置输出宽度，使其输出格式更规整，每一行结束后输出换行符。
- **`main` 函数**：提示用户输入要打印的杨辉三角的行数 `n`，调用 `printPascalTriangle` 函数来打印相应行数的杨辉三角。

递推算法通常是基于已知的初始状态或前面的计算结果，按照一定的规律逐步推出后续的结果，在很多数学计算以及具有规律性演变的问题求解中有着广泛的应用。 


