以下是几个使用C++实现递归算法的常见示例，展示其在不同问题场景下的应用：

### 示例一：计算阶乘

阶乘的数学定义为：对于正整数 `n`，`n! = n * (n - 1) * (n - 2) * … * 2 * 1`，用递归的方式可以这样实现：

```cpp
#include <iostream>

using namespace std;

// 递归计算n的阶乘的函数
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "请输入要计算阶乘的正整数: ";
    cin >> n;
    int result = factorial(n);
    cout << n << " 的阶乘为: " << result << endl;
    return 0;
}
```

**代码解释**：
- **`factorial` 函数**：
    - **递归基情况**：当 `n` 等于 `0` 时，按照阶乘的定义，`0! = 1`，所以直接返回 `1`。这是递归终止的条件，避免无限递归下去。
    - **递归调用**：对于 `n` 大于 `0` 的情况，根据阶乘的定义 `n! = n * (n - 1)!`，所以通过 `return n * factorial(n - 1)` 进行递归调用，也就是用当前的 `n` 乘以 `n - 1` 的阶乘（通过再次调用 `factorial` 函数来获取），不断这样递归下去，直到 `n` 递减到 `0` 触发递归基情况，然后再逐步回溯计算出最终的 `n` 的阶乘结果。
- **`main` 函数**：提示用户输入要计算阶乘的正整数 `n`，调用 `factorial` 函数计算其阶乘值，并输出展示给用户。

### 示例二：斐波那契数列

斐波那契数列指的是这样一个数列：0、1、1、2、3、5、8、13、21、34…… ，从第三项开始，每一项都等于前两项之和，使用递归实现如下：

```cpp
#include <iostream>

using namespace std;

// 递归计算斐波那契数列第n项的函数
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "请输入要计算的斐波那契数列的项数: ";
    cin >> n;
    int result = fibonacci(n);
    cout << "斐波那契数列第" << n << "项的值为: " << result << endl;
    return 0;
}
```

**代码解释**：
- **`fibonacci` 函数**：
    - **递归基情况**：当 `n` 等于 `0` 时返回 `0`，当 `n` 等于 `1` 时返回 `1`，这是数列前两项已知的值，也是递归终止的条件。
    - **递归调用**：对于 `n` 大于 `1` 的情况，根据斐波那契数列的定义，第 `n` 项等于第 `n - 1` 项和第 `n - 2` 项之和，所以通过 `return fibonacci(n - 1) + fibonacci(n - 2)` 进行递归调用，分别去求 `n - 1` 项和 `n - 2` 项的值（再次调用 `fibonacci` 函数），不断递归下去，直到 `n` 递减到 `0` 或者 `1` 触发递归基情况，然后再逐步回溯计算出第 `n` 项的值。
- **`main` 函数**：提示用户输入要计算的斐波那契数列的项数 `n`，调用 `fibonacci` 函数计算该项的值，并输出展示给用户。

### 示例三：汉诺塔问题

汉诺塔问题是有三根柱子，初始时在一根柱子上按从小到大顺序叠放着 `n` 个圆盘，要把这些圆盘全部移到另一根柱子上，移动过程中需遵循大盘不能放在小盘上面的规则，用递归实现如下：

```cpp
#include <iostream>

using namespace std;

// 汉诺塔移动步骤的递归函数
void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        std::cout << "将第1个圆盘从 " << from << " 柱移到 " << to << " 柱" << endl;
        return;
    }
    hanoi(n - 1, from, to, aux);
    std::cout << "将第" << n << "个圆盘从 " << from << " 柱移到 " << to << " 柱" << endl;
    hanoi(n - 1, aux, from, to);
}

int main() {
    int numDisks;
    cout << "请输入汉诺塔圆盘的个数: ";
    cin >> numDisks;
    hanoi(numDisks, 'A', 'B', 'C');
    return 0;
}
```

**代码解释**：
- **`hanoi` 函数**：
    - **递归基情况**：当 `n` 等于 `1` 时，只需要把这一个圆盘从起始柱子（`from`）直接移到目标柱子（`to`），并输出相应的移动步骤提示信息，然后结束函数调用，这就是递归终止的条件。
    - **递归调用**：对于 `n` 大于 `1` 的情况，需要先把上面的 `n - 1` 个圆盘借助目标柱子（`to`）移到辅助柱子（`aux`），这通过 `hanoi(n - 1, from, to, aux)` 来实现；接着把最底下的第 `n` 个圆盘从起始柱子（`from`）移到目标柱子（`to`），并输出相应的移动步骤提示信息；最后再把辅助柱子（`aux`）上的 `n - 1` 个圆盘借助起始柱子（`from`）移到目标柱子（`to`），通过 `hanoi(n - 1, aux, from, to)` 来完成，如此不断递归下去，直到 `n` 递减到 `1` 触发递归基情况，就完成了整个汉诺塔的移动步骤输出。
- **`main` 函数**：提示用户输入汉诺塔圆盘的个数 `numDisks`，调用 `hanoi` 函数并传入相应的柱子标识（这里简单用 `A`、`B`、`C` 表示三根柱子），开始按照汉诺塔规则输出移动步骤。

递归算法就是在函数的定义中使用函数自身的调用，通过合理设置递归基情况来避免无限递归，并且利用递归调用逐步解决问题，将大问题不断拆解为更小的、与原问题结构相似的子问题来求解。 



### 示例四：二叉树遍历（以先序遍历为例）

假设我们有如下定义的二叉树节点结构体：

```cpp
#include <iostream>

// 二叉树节点结构体定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

下面是使用递归实现二叉树先序遍历的代码：

```cpp
// 先序遍历二叉树的递归函数
void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // 构建一个简单的二叉树示例
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "先序遍历结果: ";
    preorderTraversal(root);
    std::cout << endl;

    return 0;
}
```

**代码解释**：
- **`preorderTraversal` 函数**：
    - **递归基情况**：当传入的二叉树节点指针 `root` 为 `NULL`，说明已经遍历到了叶子节点的下一层（不存在节点了），此时直接返回，结束当前的递归调用，这就是递归终止的条件。
    - **递归调用**：按照先序遍历的顺序（根节点 -> 左子树 -> 右子树），首先输出当前根节点的值（`std::cout << root->val << " ";`），然后递归调用 `preorderTraversal` 函数去遍历左子树（`preorderTraversal(root->left);`），再递归调用去遍历右子树（`preorderTraversal(root->right);`），这样不断递归下去，直到遇到 `NULL` 节点触发递归基情况，就完成了整个二叉树的先序遍历并输出相应节点的值。
- **`main` 函数**：首先手动构建了一个简单的二叉树示例，然后调用 `preorderTraversal` 函数对构建好的二叉树进行先序遍历，并输出遍历的结果展示给用户。

递归在处理具有层次结构或者可分解为相似子问题的情况（比如二叉树结构、分治算法相关问题等）时非常方便，可以简洁地表达问题的求解逻辑，但要注意合理控制递归深度等，避免出现栈溢出等问题。 



### 示例五：计算字符串的长度

下面是使用递归方式来计算字符串长度的代码示例，虽然在实际中通常会使用 `strlen` 等库函数来实现，但这里展示一下递归的思路：

```cpp
#include <iostream>
#include <string>

using namespace std;

// 递归计算字符串长度的函数
int stringLength(const char* str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + stringLength(str + 1);
}

int main() {
    string input = "Hello";
    const char* str = input.c_str();
    int length = stringLength(str);
    cout << "字符串 " << input << " 的长度为: " << length << endl;
    return 0;
}
```

**代码解释**：
- **`stringLength` 函数**：
    - **递归基情况**：当字符串指针所指向的字符为 `\0`（字符串结束标志）时，说明已经遍历到了字符串的末尾，此时字符串长度为 `0`，直接返回 `0`，这就是递归终止的条件。
    - **递归调用**：对于字符串还未结束的情况，每经过一个字符，字符串长度就应该加 `1`，所以通过 `return 1 + stringLength(str + 1)` 进行递归调用，先加上当前字符（计为长度 `1`），然后将字符串指针向后移动一位（`str + 1`），继续去判断下一个字符位置，不断递归下去，直到遇到 `\0` 字符触发递归基情况，然后逐步回溯计算出整个字符串的长度。
- **`main` 函数**：首先定义了一个字符串 `input`，然后获取其对应的字符指针 `str`，调用 `stringLength` 函数计算字符串长度，并输出展示给用户。

递归算法可以从不同角度去解决问题，将复杂的问题通过不断拆解转化为更简单的子问题，依据递归基情况来最终汇总得到整个问题的答案。 



### 示例六：整数划分问题

整数划分是指把一个正整数 `n` 表示成一系列正整数之和的形式，例如对于整数 `4`，它的划分有：`4`，`3 + 1`，`2 + 2`，`2 + 1 + 1`，`1 + 1 + 1 + 1`。下面是用递归实现计算整数划分个数的代码示例：

```cpp
#include <iostream>

using namespace std;

// 递归计算整数n的划分个数的函数
int partition(int n, int m) {
    if (n == 1 || m == 1) {
        return 1;
    }
    if (n < m) {
        return partition(n, n);
    }
    if (n == m) {
        return 1 + partition(n, m - 1);
    }
    return partition(n, m - 1) + partition(n - m, m);
}

int main() {
    int n;
    cout << "请输入要进行划分的正整数: ";
    cin >> n;
    int result = partition(n, n);
    cout << "整数 " << n << " 的划分个数为: " << result << endl;
    return 0;
}
```

**代码解释**：
- **`partition` 函数**：
    - **递归基情况**：当 `n` 等于 `1` 或者 `m` 等于 `1` 时，意味着只有一种划分方式（要么全是 `1` 相加，要么就是这个数本身），所以直接返回 `1`，这是递归终止的条件。
    - **其他情况分析与递归调用**：
        - 当 `n` 小于 `m` 时，此时划分中最大的数不能超过 `n`，所以等同于对 `n` 以 `n` 为最大数进行划分，即 `return partition(n, n)`。
        - 当 `n` 等于 `m` 时，有两种情况，一种是包含 `m` 这个数的划分（就是 `n` 本身），另一种是不包含 `m` 的划分（也就是对 `n` 以 `m - 1` 为最大数进行划分），所以返回 `1 + partition(n, m - 1)`。
        - 当 `n` 大于 `m` 时，同样有两种情况，一种是划分中包含 `m` 的情况，此时相当于先拿出一个 `m`，剩下的 `n - m` 再以 `m` 为最大数进行划分（`partition(n - m, m)`）；另一种是划分中不包含 `m` 的情况，也就是对 `n` 以 `m - 1` 为最大数进行划分（`partition(n, m - 1)`），所以返回 `partition(n, m - 1) + partition(n - m, m)`。
- **`main` 函数**：提示用户输入要进行划分的正整数 `n`，调用 `partition` 函数计算其划分个数，并输出展示给用户。

通过递归可以巧妙地处理像整数划分这样较为复杂的组合数学问题，将问题根据不同的条件拆解为更小的子问题来逐步求解。 



### 示例七：全排列问题

全排列是指从 `n` 个不同元素中取出 `n` 个元素的所有排列的个数，例如对于 `1`、`2`、`3` 这三个数，它们的全排列有 `123`、`132`、`213`、`231`、`312`、`321`。以下是用递归实现求给定数组元素全排列的代码示例：

```cpp
#include <iostream>
#include <vector>

using namespace std;

// 交换两个元素的位置
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 递归生成全排列的函数
void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    permute(nums, 0, result);

    cout << "全排列结果如下：" << endl;
    for (vector<int> perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**代码解释**：
- **`swap` 函数**：这是一个简单的辅助函数，用于交换两个整数的位置，通过引入一个临时变量 `temp`，实现了两个元素值的互换，方便后续在生成全排列过程中交换数组元素的位置。
- **`permute` 函数**：
    - **递归基情况**：当 `start` 等于数组 `nums` 大小减 `1` 时，意味着已经确定了前面所有元素的排列情况，此时当前的数组状态就是一种全排列结果，将其添加到结果集 `result` 中（`result.push_back(nums);`），然后返回，结束当前的递归调用，这就是递归终止的条件。
    - **递归调用与元素交换**：通过一个 `for` 循环从 `start` 位置开始到数组末尾，每次先交换 `nums[start]` 和 `nums[i]` 的位置，这样就改变了当前的排列情况，然后递归调用 `permute` 函数，传入`permute`函数（续）：

传入`start + 1`，表示继续去确定后面元素的排列情况，等这次递归调用结束后（也就是后面元素的全排列情况都已经生成完毕），再把交换过的元素换回来（`swap(nums[start], nums[i]);`），这样可以保证下一次循环交换其他元素位置时，数组状态是原始的，进而尝试不同的排列组合，如此不断递归下去，直到达到递归基情况，就生成了所有的全排列情况。

- **`main`函数**：
首先定义了一个示例的整数数组`nums`，并创建了一个二维向量`result`用于存放全排列的结果。然后调用`permute`函数，从索引为`0`的位置开始生成全排列，将结果存放在`result`中。最后通过两层嵌套的循环遍历`result`，将每一种全排列结果输出展示给用户，方便查看具体的全排列内容。

递归算法在处理这类需要穷举所有可能情况、并且问题可以分解为相似子问题的场景中（像全排列、整数划分等）有着很好的应用，它能够以一种较为简洁直观的代码结构来实现复杂的逻辑，但也要注意递归深度可能导致的栈空间占用问题，在一些对性能和资源要求较高的场景下，可能需要考虑使用非递归的方式或者对递归进行适当优化（比如通过尾递归优化等手段，不过C++标准并没有强制要求编译器对尾递归进行优化，不同编译器表现不同）来解决相关问题。

例如在全排列问题中，如果输入的元素个数非常多，递归调用的深度会很深，可能会出现栈溢出的情况，这时可以考虑使用迭代等其他方式来实现全排列的生成，比如基于字典序算法等非递归方式来生成全排列，以此来应对可能出现的性能和资源方面的挑战。 



### 示例八：计算二叉树的高度

下面是使用递归方式来计算二叉树高度的代码示例，二叉树的高度定义为从根节点到叶节点最长路径上的节点数（根节点高度为1）。

假设二叉树节点结构体定义如下：

```cpp
#include <iostream>

// 二叉树节点结构体定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

计算二叉树高度的递归函数代码如下：

```cpp
// 递归计算二叉树高度的函数
int getTreeHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int main() {
    // 构建一个简单的二叉树示例
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = getTreeHeight(root);
    std::cout << "该二叉树的高度为: " << height << endl;
    return 0;
}
```

**代码解释**：
- **`getTreeHeight`函数**：
    - **递归基情况**：当传入的二叉树节点指针`root`为`NULL`时，说明已经到达了二叉树的叶节点的下一层（不存在节点了），此时这棵子树的高度为`0`，直接返回`0`，这就是递归终止的条件。
    - **递归调用及计算**：分别递归地调用`getTreeHeight`函数去计算左子树的高度（`leftHeight = getTreeHeight(root->left);`）和右子树的高度（`rightHeight = getTreeHeight(root->right);`）。然后根据二叉树高度的定义，整棵树的高度就是左、右子树高度中的最大值再加`1`（因为要算上根节点这一层），所以返回`std::max(leftHeight, rightHeight) + 1`。通过不断这样递归下去，从叶节点往上逐步计算，最终可以得到整棵二叉树的高度。
- **`main`函数**：首先手动构建了一个简单的二叉树示例，然后调用`getTreeHeight`函数计算该二叉树的高度，并输出展示给用户。

递归在处理二叉树相关的很多属性计算（如高度、节点个数、是否平衡等）问题上非常方便，因为二叉树本身具有天然的递归结构，每个子树都可以看成是一棵独立的二叉树，和整棵树有着相似的结构特点，利用这一点可以简洁地通过递归算法来求解相关问题。

总之，递归算法是一种强大的编程技巧，在很多领域尤其是处理具有层次结构、可分解为相似子问题的场景中发挥着重要作用，但在实际应用中要充分考虑到递归深度、栈空间等因素对程序运行的影响，合理运用以达到良好的编程效果。 



### 示例九：判断字符串是否为回文

回文是指一个字符串正着读和倒着读都一样，例如“level”“racecar”等就是回文。以下是使用递归实现判断字符串是否为回文的代码示例：

```cpp
#include <iostream>
#include <string>

using namespace std;

// 递归判断字符串是否为回文的函数
bool isPalindrome(const char* str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start]!= str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string input = "racecar";
    const char* str = input.c_str();
    bool result = isPalindrome(str, 0, input.length() - 1);
    if (result) {
        cout << "该字符串是回文" << endl;
    }
    else {
        cout << "该字符串不是回文" << endl;
    }
    return 0;
}
```

**代码解释**：
- **`isPalindrome`函数**：
    - **递归基情况**：当`start`大于等于`end`时，说明已经比较完了字符串的一半或者整个字符串只有一个字符等情况，此时字符串就是回文，返回`true`，这是递归终止的条件。
    - **比较与递归调用**：先比较字符串首尾字符（`str[start]`和`str[end]`），如果不相等，那肯定不是回文，直接返回`false`；如果相等，就继续递归调用`isPalindrome`函数，将比较的范围缩小，也就是把`start`加`1`，`end`减`1`（`return isPalindrome(str, start + 1, end - 1);`），去比较里面一层的字符是否相等，不断这样递归下去，直到达到递归基情况，从而判断出整个字符串是否为回文。
- **`main`函数**：首先定义了一个字符串`input`，获取其对应的字符指针`str`，然后调用`isPalindrome`函数，传入起始位置`0`和末尾位置（字符串长度减`1`），根据返回结果判断并输出该字符串是否为回文的信息展示给用户。

递归在这种需要比较对称位置元素来判断某种性质（如回文性质）的问题上可以使代码逻辑更加清晰简洁，通过不断缩小比较范围，利用递归基情况来最终得出结论。 



### 示例十：组合问题

组合问题是指从 `n` 个不同元素中取出 `m` 个元素的所有组合情况，例如从 `5` 个元素中取出 `3` 个元素的组合情况。以下是用递归实现计算组合的代码示例：

```cpp
#include <iostream>
#include <vector>

using namespace std;

// 递归计算组合的函数
void combine(int n, int m, int start, vector<int>& cur, vector<vector<int>>& result) {
    if (cur.size() == m) {
        result.push_back(cur);
        return;
    }
    for (int i = start; i <= n; i++) {
        cur.push_back(i);
        combine(n, m, i + 1, cur, result);
        cur.pop_back();
    }
}

int main() {
    int n = 5;
    int m = 3;
    vector<int> cur;
    vector<vector<int>> result;
    combine(n, m, 1, cur, result);

    cout << "从 " << n << " 个元素中取 " << m << " 个元素的组合情况如下：" << endl;
    for (vector<int> comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**代码解释**：
- **`combine`函数**：
    - **递归基情况**：当当前组合`cur`的元素个数等于要选取的元素个数`m`时，说明已经得到了一种有效的组合情况，将其添加到结果集`result`中（`result.push_back(cur);`），然后返回，结束当前的递归调用，这就是递归基情况。
    - **递归调用与元素操作**：通过一个`for` 循环从`start`位置开始到`n`，每次先把当前的数字`i`添加到当前组合`cur`中（`cur.push_back(i);`），然后递归调用`combine`函数，传入`i + 1`作为新的起始位置，继续去选取后面的元素来组成组合，等这次递归调用结束后（也就是后面元素组成的组合情况都已经尝试完毕），再把刚才添加的元素从`cur`中移除（`cur.pop_back();`），这样可以保证下一次循环添加其他元素时，当前组合状态是正确的，进而尝试不同的组合情况，如此不断递归下去，直到达到递归基情况，就生成了所有的组合情况。
- **`main`函数**：
首先定义了要选取的总元素个数`n`和要选取的元素个数`m`，并创建了一个空的向量`cur`用于存放当前正在生成的组合元素以及一个二维向量`result`用于存放最终的组合结果。然后调用`combine`函数，从起始位置`1`开始生成组合，将结果存放在`result`中。最后通过两层嵌套的循环遍历`result`，将每一种组合结果输出展示给用户，方便查看具体的组合内容。

递归在处理组合、排列等组合数学相关的问题上有着广泛应用，能很好地体现出分治、逐步构建结果的思路，但同样需要留意递归深度带来的栈空间占用问题以及运行效率等方面，在实际应用中根据具体场景可考虑适当优化或者采用其他非递归的方式来解决相关问题。 



这些示例展示了递归算法在不同类型问题中的应用，通过不断地将大问题拆解为更小的、结构相似的子问题，并设置合理的递归基情况来终止递归，从而高效地解决各类复杂的问题。 


