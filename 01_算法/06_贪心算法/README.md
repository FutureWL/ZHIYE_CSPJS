以下是几个使用C++实现贪心算法的常见示例，展示其在不同问题场景下的应用：

### 示例一：找零问题

假设我们有不同面额的货币，如1元、5元、10元、20元等，现在要使用最少的货币数量来凑出给定的金额。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 货币面额
vector<int> denominations = {20, 10, 5, 1};

// 贪心算法实现找零
vector<int> makeChange(int amount) {
    vector<int> result(denominations.size(), 0);
    for (size_t i = 0; i < denominations.size(); i++) {
        result[i] = amount / denominations[i];
        amount %= denominations[i];
    }
    return result;
}

int main() {
    int amount = 63;
    vector<int> change = makeChange(amount);
    cout << "凑出 " << amount << " 元需要的货币数量如下：" << endl;
    for (size_t i = 0; i < denominations.size(); i++) {
        cout << denominations[i] << " 元：" << change[i] << " 张" << endl;
    }
    return 0;
}
```

**代码解释**：

- **`makeChange` 函数**：
    - 首先创建一个与货币面额数量相同大小的向量 `result`，用于记录每种面额货币的使用数量，初始值都设为 `0`。
    - 然后通过一个循环遍历货币面额数组 `denominations`。在每次循环中，先计算当前面额货币可以使用的张数，即 `amount` 除以当前面额 `denominations[i]`，并将结果存放在 `result[i]` 中。接着更新剩余需要凑出的金额，通过取模运算 `amount %= denominations[i]`，将已经用当前面额凑出的部分减掉。这个过程就是贪心的体现，每次都优先选择面额尽可能大的货币，因为这样能使货币的总数量尽量少。
    - 循环结束后，`result` 向量中就记录了每种面额货币所需的数量，最后返回这个向量。

- **`main` 函数**：
    - 首先定义了要凑出的金额 `amount`（这里以 `63` 元为例，可以修改为其他金额），然后调用 `makeChange` 函数得到找零的结果 `change`，最后通过循环输出每种面额货币的使用张数，展示具体的找零方案。

### 示例二：活动安排问题

假设有一系列活动，每个活动都有开始时间和结束时间，要求在有限的时间内安排尽可能多的活动，且活动之间不能有时间重叠。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 活动结构体，包含开始时间和结束时间
struct Activity {
    int start;
    int end;
};

// 比较函数，用于按照活动结束时间排序，使得结束时间早的活动排在前面
bool compareActivities(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

// 贪心算法实现活动安排
int activitySelection(vector<Activity>& activities) {
    if (activities.empty()) {
        return 0;
    }
    // 先按照活动结束时间对活动进行排序
    sort(activities.begin(), activities.end(), compareActivities);
    int count = 1;
    int lastEnd = activities[0].end;
    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}

int main() {
    vector<Activity> activities = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 13},
        {12, 14}
    };
    int selectedCount = activitySelection(activities);
    cout << "最多可安排的活动数量为: " << selectedCount << endl;
    return 0;
}
```

**代码解释**：

- **`compareActivities` 函数**：
    - 这是一个自定义的比较函数，用于 `sort` 函数对活动数组进行排序时的比较规则。按照活动结束时间从小到大排序，这样就能保证在后续贪心选择时，优先选择结束时间早的活动，为安排更多活动腾出更多时间。

- **`activitySelection` 函数**：
    - 首先判断活动数组是否为空，如果为空则直接返回 `0`，表示没有活动可安排。
    - 接着调用 `sort` 函数，根据自定义的比较函数 `compareActivities` 对活动数组进行排序，使得活动按照结束时间升序排列。
    - 初始化一个变量 `count` 为 `1`，表示已经选择了第一个活动（因为至少会选择一个最早结束的活动），同时记录第一个活动的结束时间 `lastEnd`。
    - 通过一个循环遍历排序后的活动数组（从第二个活动开始，索引为 `1`），对于每个活动，判断其开始时间是否大于等于上一个选择活动的结束时间，如果满足这个条件，说明该活动与已选活动没有时间重叠，可以选择这个活动，此时将 `count` 加 `1`，并更新 `lastEnd` 为当前活动的结束时间。
    - 循环结束后，`count` 就是能够安排的最多活动数量，最后返回这个值。

- **`main` 函数**：
    - 首先定义了一个活动数组 `activities`，包含了多个活动的开始时间和结束时间信息（这里可以根据实际情况修改活动的具体时间安排）。然后调用 `activitySelection` 函数计算最多可安排的活动数量，并输出展示给用户。

### 示例三：分数背包问题

有 `n` 个物品，每个物品都有重量和价值，背包有一定的承重限制，要求在背包承重允许的范围内装入物品，使得装入物品的总价值最大（每个物品可以分割取部分装入背包）。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 物品结构体，包含重量和价值
struct Item {
    int weight;
    int value;
};

// 计算每个物品的单位价值（价值/重量）
double unitValue(const Item& item) {
    return static_cast<double>(item.value) / item.weight;
}

// 比较函数，用于按照单位价值排序，使得单位价值高的物品排在前面
bool compareItems(const Item& a, const Item& b) {
    return unitValue(a) > unitValue(b);
}

// 贪心算法实现分数背包
double fractionalKnapsack(vector<Item>& items, int capacity) {
    if (items.empty()) {
        return 0;
    }
    // 先按照单位价值对物品进行排序
    sort(items.begin(), items.end(), compareItems);
    double totalValue = 0;
    for (size_t i = 0; i < items.size(); i++) {
        if (capacity >= items[i].weight) {
            // 如果背包容量大于等于物品重量，直接装入整个物品
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // 如果背包容量小于物品重量，装入部分物品
            totalValue += unitValue(items[i]) * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int capacity = 50;
    double maxValue = fractionalKnapsack(items, capacity);
    cout << "背包能装入的最大价值为: " << maxValue << endl;
    return 0;
}
```

**代码解释**：

- **`unitValue` 函数**：
    - 这个函数用于计算给定物品的单位价值，即通过将物品的价值除以重量，得到每单位重量的价值，返回类型为 `double`，方便后续比较和计算。

- **`compareItems` 函数**：
    - 这是一个自定义的比较函数，用于 `sort` 函数对物品数组进行排序时的比较规则。按照物品的单位价值从大到小排序，这样就能保证在后续贪心选择时，优先选择单位价值高的物品装入背包，以期望获得最大的总价值。

- **`fractionalKnapsack` 函数**：
    - 首先判断物品数组是否为空，如果为空则直接返回 `0`，表示没有物品可装入背包，总价值为 `0`。
    - 接着调用 `sort` 函数，根据自定义的比较函数 `compareItems` 对物品数组进行排序，使得物品按照单位价值降序排列。
    - 初始化一个变量 `totalValue` 为 `0`，用于记录装入背包的物品总价值。
    - 通过一个循环遍历排序后的物品数组，对于每个物品进行如下判断和操作：
        - 如果背包的剩余容量 `capacity` 大于等于当前物品的重量 `items[i].weight`，说明可以将整个物品装入背包，此时将该物品的价值 `items[i].value` 加到 `totalValue` 中，并更新背包剩余容量 `capacity -= items[i].weight`。
        - 如果背包的剩余容量小于当前物品的重量，说明不能装入整个物品，只能装入部分物品，此时根据物品的单位价值计算能装入部分的价值（`unitValue(items[i]) * capacity`），加到 `totalValue` 中，然后跳出循环，因为背包已经装满了（按贪心策略已达到当前最大价值）。
    - 循环结束后，`totalValue` 就是背包能够装入的最大价值，最后返回这个值。

- **`main` 函数**：
    - 首先定义了一个物品数组 `items`，包含了多个物品的重量和价值信息（这里可以根据实际情况修改物品的具体属性），以及背包的承重限制 `capacity`（这里以 `50` 为例，可以修改为其他值）。然后调用 `fractionalKnapsack` 函数计算背包能装入的最大价值，并输出展示给用户。

贪心算法在这类问题中通过每次选择当前局部最优的策略（如找零问题选最大面额、活动安排选最早结束活动、分数背包选单位价值最高物品等），在满足问题特定条件下，往往能够最终达到全局最优或者接近全局最优的解。不过要注意的是，并不是所有问题都适合用贪心算法解决，需要问题本身具有贪心选择性质和最优子结构性质才行。 



这些示例展示了贪心算法在不同类型问题中的应用，通过合理地定义贪心策略（选择规则），按照这个策略逐步选择元素，最终解决问题，帮助我们高效地处理一些具有特定结构特点的优化问题。 



### 示例四：哈夫曼编码问题

哈夫曼编码是一种用于数据无损压缩的编码方式，它基于字符出现的频率来构建一种编码树，使得出现频率高的字符编码较短，出现频率低的字符编码较长，从而达到整体编码长度最短的效果。以下是使用C++实现哈夫曼编码的贪心算法示例（简化版，主要聚焦贪心策略部分）：

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

// 哈夫曼树节点结构体
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char ch, int freq) : data(ch), frequency(freq), left(NULL), right(NULL) {}
};

// 比较函数，用于在优先队列中按照节点频率从小到大排序（构建最小堆）
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// 构建哈夫曼树的函数，体现贪心策略
HuffmanNode* buildHuffmanTree(unordered_map<char, int>& frequencyMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;
    // 将每个字符及其对应的频率节点加入最小堆
    for (auto& it : frequencyMap) {
        minHeap.push(new HuffmanNode(it.first, it.second));
    }
    while (minHeap.size() > 1) {
        // 取出频率最小的两个节点
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();
        // 创建一个新节点，频率为两个子节点频率之和，作为父节点
        HuffmanNode* parent = new HuffmanNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        // 将新的父节点加入最小堆
        minHeap.push(parent);
    }
    return minHeap.top();
}

// 递归生成哈夫曼编码的函数
void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == NULL) {
        return;
    }
    if (root->data!= '\0') {
        huffmanCodes[root->data] = code;
    }
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// 主函数，展示哈夫曼编码生成过程
int main() {
    unordered_map<char, int> frequencyMap = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };
    HuffmanNode* root = buildHuffmanTree(frequencyMap);
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);
    for (auto& it : huffmanCodes) {
        cout << it.first << " : " << it.second << endl;
    }
    return 0;
}
```

**代码解释**：

- **`HuffmanNode` 结构体**：
    - 定义了哈夫曼树节点的结构，包含字符数据（如果是叶子节点则存储实际字符，非叶子节点可以用 `\0` 表示）、字符出现的频率 `frequency`，以及左右子节点指针 `left` 和 `right`，方便构建哈夫曼树结构。

- **`CompareNodes` 结构体**：
    - 这是一个自定义的比较结构体，用于定义优先队列（最小堆）中元素的比较规则。在这里按照哈夫曼节点的频率从小到大进行排序，使得每次从堆中取出的都是频率最小的节点，这是贪心算法的关键步骤之一，即总是优先合并频率最小的元素来构建哈夫曼树。

- **`buildHuffmanTree` 函数**：
    - 首先创建一个优先队列（最小堆） `minHeap`，用于存放哈夫曼树的节点。
    - 通过一个循环遍历字符频率映射表 `frequencyMap`，将每个字符及其对应的频率构建成哈夫曼节点，并加入到最小堆中。
    - 然后进入一个循环，只要堆中节点数量大于 `1`，就执行以下操作：
        - 从堆中取出频率最小的两个节点（`left` 和 `right`），这就是贪心选择的体现，每次选择当前频率最低的两个元素进行合并。
        - 创建一个新的节点 `parent`，其频率为取出的两个子节点频率之和，左右子节点分别指向刚才取出的两个节点，这个新节点就作为它们的父节点，模拟构建哈夫曼树的合并过程。
        - 将新创建的父节点 `parent` 加入到最小堆中，继续参与后续的合并操作。
    - 当循环结束时，堆中只剩下一个节点，这个节点就是构建好的哈夫曼树的根节点，最后返回这个根节点。

- **`generateHuffmanCodes` 函数**：
    - 这是一个递归函数，用于根据构建好的哈夫曼树生成每个字符对应的哈夫曼编码。
    - 如果传入的根节点 `root` 为 `NULL`，直接返回，结束递归。
    - 如果根节点的字符数据不为 `\0`，说明是叶子节点，将当前的编码 `code` 存入到编码映射表 `huffmanCodes` 中，对应这个叶子节点代表的字符。
    - 然后分别递归调用该函数，处理左子树和右子树，对于左子树，编码加上 `0`（表示向左分支走的编码），对于右子树，编码加上 `1`（表示向右分支走的编码），通过不断递归，最终生成所有字符的哈夫曼编码。

- **`main` 函数**：
    - 首先定义了一个字符频率映射表 `frequencyMap`，模拟了不同字符出现的频率情况（这里可以根据实际需要修改字符及频率）。
    - 调用 `buildHuffmanTree` 函数构建哈夫曼树的根节点 `root`。
    - 创建一个空的编码映射表 `huffmanCodes`，用于存放生成的哈夫曼编码，然后调用 `generateHuffman- **`generateHuffmanCodes`函数（续）**：
    - 调用 `generateHuffmanCodes` 函数，传入哈夫曼树的根节点 `root` 以及初始空编码 `""`，开始生成各个字符对应的哈夫曼编码，并将结果存放在 `huffmanCodes` 映射表中。
    - 最后通过一个循环遍历 `huffmanCodes` 映射表，输出每个字符及其对应的哈夫曼编码，展示最终的编码结果，方便查看不同字符是如何基于贪心策略构建的哈夫曼树来获得相应编码的。

贪心算法在哈夫曼编码问题中，通过总是选择频率最小的节点进行合并来构建哈夫曼树，以此逐步构建出整体编码长度最短的编码方式，符合贪心选择性质和最优子结构性质，从而实现高效的数据压缩编码方案。

### 示例五：拼接最大数字问题

给定一个非负整数数组，要将这些整数拼接起来组成一个最大的数字。例如，给定 `[3, 30, 34, 5, 9]`，拼接出的最大数字为 `9534330`。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 比较函数，用于确定两个数字拼接后的大小顺序，以决定排序方式
bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

// 贪心算法实现拼接最大数字
string largestNumber(vector<int>& nums) {
    vector<string> numStrs;
    for (int num : nums) {
        numStrs.push_back(to_string(num));
    }
    sort(numStrs.begin(), numStrs.end(), compare);
    string result;
    for (string numStr : numStrs) {
        result += numStr;
    }
    if (result[0] == '0') {
        return "0";
    }
    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    string largest = largestNumber(nums);
    cout << "拼接出的最大数字为: " << largest << endl;
    return 0;
}
```

**代码解释**：

- **`compare` 函数**：
    - 这是一个自定义的比较函数，用于 `sort` 函数对数字字符串数组进行排序时的比较规则。它判断将两个数字字符串 `a` 和 `b` 拼接起来（`a + b` 和 `b + a`）哪种顺序拼接后得到的数字更大，按照这个规则进行排序，就是贪心策略的体现。因为每次都优先把按照这样的比较规则能组成更大数字的字符串排在前面，期望最终拼接出的整个数字是最大的。

- **`largestNumber` 函数**：
    - 首先创建一个字符串向量 `numStrs`，通过一个循环将输入的整数数组 `nums` 中的每个整数转换为字符串，并添加到 `numStrs` 中。
    - 接着调用 `sort` 函数，根据自定义的比较函数 `compare` 对 `numStrs` 进行排序，使得数字字符串按照能拼接出更大数字的顺序排列。
    - 然后创建一个空字符串 `result`，通过一个循环将排序后的数字字符串依次拼接起来，存放在 `result` 中。
    - 最后进行一个特殊情况判断，如果拼接后的结果字符串首字符是 `0`，说明整个数字就是 `0`（例如输入数组全是 `0` 的情况），直接返回 `"0"`；否则返回拼接好的 `result` 字符串，它就是能拼接出的最大数字。

- **`main` 函数**：
    - 首先定义了一个整数数组 `nums`（这里可以根据实际情况修改数组中的元素），然后调用 `largestNumber` 函数得到拼接出的最大数字字符串，并输出展示给用户。

贪心算法在此问题中通过定义合适的比较规则，决定数字的拼接顺序，每次选择当前看似能让整体数字更大的局部最优选择（数字字符串的排序顺序），最终达到拼接出最大数字的全局最优结果，当然前提是这个问题具有可以通过这样逐步贪心选择来达到最优解的性质。

### 示例六：任务调度问题（带截止时间和收益）

假设有多个任务，每个任务都有一个截止时间和完成该任务能获得的收益，一个任务必须在其截止时间之前完成才能获得收益，要求安排任务执行顺序，使得总收益最大。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 任务结构体，包含任务编号、截止时间和收益
struct Task {
    int id;
    int deadline;
    int profit;
};

// 比较函数，用于按照收益从大到小对任务排序
bool compareTasks(const Task& a, const Task& b) {
    return a.profit > b.profit;
}

// 贪心算法实现任务调度
int jobScheduling(vector<Task>& tasks) {
    if (tasks.empty()) {
        return 0;
    }
    // 先按照收益对任务进行排序
    sort(tasks.begin(), tasks.end(), compareTasks);
    int maxDeadline = 0;
    for (Task task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }
    vector<bool> slots(maxDeadline, false);
    int totalProfit = 0;
    for (Task task : tasks) {
        for (int i = task.deadline - 1; i >= 0; i--) {
            if (!slots[i]) {
                slots[i] = true;
                totalProfit += task.profit;
                break;
            }
        }
    }
    return totalProfit;
}

int main() {
    vector<Task> tasks = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    int maxProfit = jobScheduling(tasks);
    cout << "最大总收益为: " << maxProfit << endl;
    return 0;
}
```

**代码解释**：

- **`compareTasks` 函数**：
    - 这是一个自定义的比较函数，用于 `sort` 函数对任务数组进行排序时的比较规则。按照任务的收益从大到小进行排序，这样贪心策略就是优先选择收益高的任务去安排执行，期望能获得最大的总收益。

- **`jobScheduling` 函数**：
    - 首先判断任务数组是否为空，如果为空则直接返回 `0`，表示没有任务可执行，总收益为 `0`。
    - 接着调用 `sort` 函数，根据自定义的比较函数 `compareTasks` 对任务数组进行排序，使得任务按照收益降序排列。
    - 通过一个循环遍历任务数组，找出所有任务中最大的截止时间 `maxDeadline`，用于后续创建表示时间槽的数组。
    - 创建一个布尔向量 `slots`，长度为 `maxDeadline`，初始值都设为 `false`，用于标记每个时间槽是否被任务占用。
    - 再通过一个循环遍历排序后的任务数组，对于每个任务，从其截止时间往前倒推（`for (int i = task.deadline - 1; i >= 0; i--)`），检查是否有空闲的时间槽（`!slots[i]`），如果找到空闲时间槽，就将其标记为已占用（`slots[i] = true`），并把该任务的收益加到总收益 `totalProfit` 中，然后跳出内层循环，继续处理下一个任务。这个过程就是贪心选择，总是优先尝试把高收益的任务安排到合适的时间槽中。
    - 循环结束后，`totalProfit` 就是能够获得的最大总收益，最后返回这个值。

- **`main` 函数**：
    - 首先定义了一个任务数组 `tasks`，包含了多个任务的编号、截止时间和收益信息（这里可以根据实际情况修改任务的具体属性）。然后调用 `jobScheduling` 函数计算最大总收益，并输出展示给用户。

贪心算法在这个任务调度问题中，通过优先选择收益高的任务，并尽量安排到合适的时间槽中，利用了问题的贪心选择性质和最优子结构性质，来达到获得最大总收益的全局最优解（或者接近最优解的较好结果），当然前提是任务之间不存在一些复杂的依赖等关系影响这种贪心策略的有效性。

这些不同的示例充分展示了贪心算法在各种不同类型优化问题中的应用，通过巧妙地定义贪心策略，按照局部最优的选择逐步推进，在合适的问题场景下能够高效地获取全局最优或者较优的结果，不过要准确判断问题是否适合贪心算法解决，关键还是要看是否具备相应的贪心选择和最优子结构这两个重要性质。 



### 示例七：最小生成树问题（以Prim算法为例，Prim算法本质上也蕴含贪心思想）

最小生成树是指在一个连通无向图中，选择一些边连接所有顶点，且这些边的权值之和最小。以下是使用C++实现Prim算法的代码示例（为了简化，图以邻接矩阵形式表示，顶点用整数表示）：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 表示图的邻接矩阵，这里假设是简单的权值类型为int的情况，INF表示无穷大（不可达）
const int INF = 1e9;
int graph[100][100];

// 贪心算法实现Prim算法求最小生成树
int prim(int n) {
    vector<int> key(n, INF);
    vector<bool> inMST(n, false);
    key[0] = 0;
    int result = 0;
    for (int count = 0; count < n; count++) {
        int u = -1;
        // 找到未加入MST中且权值最小的顶点
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }
        inMST[u] = true;
        result += key[u];
        // 更新与u相邻顶点的权值
        for (int v = 0; v < n; v++) {
            if (graph[u][v]!= INF &&!inMST[v]) {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return result;
}

int main() {
    int n = 5;
    // 初始化邻接矩阵表示的图示例（这里可以根据实际情况修改图的连接关系和权值）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
    graph[0][1] = 2;
    graph[0][3] = 6;
    graph[1][2] = 3;
    graph[1][3] = 8;
    graph[1][4] = 5;
    graph[2][4] = 7;
    graph[3][4] = 9;

    int minCost = prim(n);
    cout << "最小生成树的总权值为: " << minCost << endl;
    return 0;
}
```

**代码解释**：

- **`prim` 函数**：
    - 首先创建两个向量，`key` 向量用于记录每个顶点到已生成的最小生成树（MST）的最小距离（权值），初始值都设为无穷大 `INF`，除了第一个顶点（通常可以任意选择一个起始顶点，这里选择索引为 `0` 的顶点）设为 `0`；`inMST` 向量用于标记每个顶点是否已经加入到最小生成树中，初始值都设为 `false`。
    - 接着进入一个循环，循环次数为图的顶点数量 `n`，每次循环执行以下操作：
        - 通过一个内层循环找到未加入到最小生成树中（`!inMST[i]`）且到已生成的最小生成树距离最小（通过比较 `key[i]` 的值，`u == -1 || key[i] < key[u]` 这个条件来判断，初始 `u` 为 `-1`，后续不断更新为距离更小的顶点）的顶点 `u`，这一步就是贪心选择的体现，每次都选择当前距离最小生成树最近的未加入顶点。
        - 将找到的顶点 `u` 标记为已加入最小生成树（`inMST[u] = true`），并把该顶点到最小生成树的距离（也就是 `key[u]` 的值）累加到结果变量 `result` 中，这个 `result` 最终就是最小生成树的总权值。
        - 然后通过另一个内层循环遍历所有顶点 `v`，对于与顶点 `u` 相邻（`graph[u][v]!= INF`）且还未加入最小生成树（`!inMST[v]`）的顶点，更新它们到最小生成树的距离（`key[v]`），取当前距离和通过顶点 `u` 连接过来的距离（`graph[u][v]`）中的最小值，这一步是为了后续能继续找到距离最小生成树最近的未加入顶点做准备，符合贪心的逐步优化过程。
    - 循环结束后，`result` 就是整个图的最小生成树的总权值，最后返回这个值。

- **`main` 函数**：
    - 首先定义了图的顶点数量 `n`（这里以 `5` 个顶点为例，可以根据实际情况修改），然后初始化邻接矩阵 `graph`，将所有元素初始化为无穷大，表示初始时各顶点之间都未连通（不可达），接着手动设置一些边的连接关系和相应的权值，模拟一个具体的图结构（这里可以根据实际需求修改图的边和权值情况）。
    - 最后调用 `prim` 函数计算最小生成树的总权值，并输出展示给用户。

Prim算法的贪心策略在于每次都选择距离当前最小生成树最近的未加入顶点及其对应的边加入到最小生成树中，通过不断重复这个贪心步骤，最终构建出权值总和最小的最小生成树，利用了图的最优子结构性质和贪心选择性质，能够有效地解决最小生成树问题，当然在实际应用中，还可以根据具体情况对算法进行优化，比如使用更高效的数据结构（如优先队列等）来提高查找未加入顶点中距离最小的那个顶点的效率等。

### 示例八：最优装载问题

最优装载问题是指有一艘船，其载重量为 `C`，有 `n` 个货物，每个货物都有各自的重量，要求在船的载重量允许范围内，尽可能多地装载货物，求最多能装载货物的数量。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心算法实现最优装载
int optimalLoading(int C, vector<int>& weights) {
    if (weights.empty()) {
        return 0;
    }
    // 按照货物重量从小到大排序
    sort(weights.begin(), weights.end());
    int count = 0;
    int currentWeight = 0;
    for (int weight : weights) {
        if (currentWeight + weight <= C) {
            currentWeight += weight;
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int C = 10;
    vector<int> weights = {1, 2, 3, 4, 5};
    int maxCount = optimalLoading(C, weights);
    cout << "最多能装载的货物数量为: " << maxCount << endl;
    return 0;
}
```

**代码解释**：

- **`optimalLoading` 函数**：
    - 首先判断货物重量数组 `weights` 是否为空，如果为空则直接返回 `0`，表示没有货物可装载，装载数量为 `0`。
    - 接着调用 `sort` 函数，按照货物重量从小到大对 `weights` 进行排序，这就是贪心策略，优先选择重量轻的货物进行装载，这样在载重量有限的情况下，能尽可能多地装入货物。
    - 初始化两个变量，`count` 用于记录已经装载的货物数量，初始值为 `0`；`currentWeight` 用于记录当前已经装载货物的总重量，初始值为 `0`。
    - 通过一个循环遍历排序后的货物重量数组，对于每个货物重量 `weight`，判断如果当前已装载货物总重量加上该货物重量不超过船的载重量 `C`（`currentWeight + weight <= C`），就将该货物装入船中，即更新 `currentWeight`（`currentWeight += weight`），同时 `count` 加 `1`，表示又装载了一个货物；如果超过了载重量，则跳出循环，因为已经不能再继续装载货物了。
    - 循环结束后，`count` 就是最多能装载的货物数量，最后返回这个值。

- **`main` 函数**：
    - 首先定义了船的载重量 `C`（这里以 `10` 为例，可以根据实际情况修改）和一个货物重量数组 `weights`（同样可以根据实际情况修改数组中的元素），然后调用 `optimalLoading` 函数计算最多- **`optimalLoading`函数（续）**：
    - 调用 `optimalLoading` 函数计算最多能装载的货物数量，并将结果存放在 `maxCount` 变量中。
    - 最后通过 `cout` 输出语句，将最多能装载的货物数量展示给用户，方便查看在给定载重量和货物重量情况下的最优装载结果。

贪心算法在最优装载问题中，通过先对货物按重量排序，然后依次选择重量轻的货物进行装载这一贪心策略，能保证在船的载重量限制下尽可能多地装入货物，达到装载货物数量最多的较优（在此问题中是最优）结果，充分利用了问题本身简单的贪心选择性质，即每次选择当前看起来能让装载数量更多的货物（也就是重量轻的货物）来逐步构建最终的装载方案。

### 示例九：单源最短路径问题（以Dijkstra算法为例，其有贪心特性）

Dijkstra算法用于解决带非负权值的图中，从一个源点到其他所有顶点的最短路径问题。以下是使用C++实现Dijkstra算法的代码示例（同样以邻接矩阵表示图，顶点用整数表示）：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 表示图的邻接矩阵，INF表示无穷大（不可达），这里简单设权值类型为int
const int INF = 1e9;
int graph[100][100];

// 贪心算法实现Dijkstra算法求单源最短路径
void dijkstra(int source, int n) {
    vector<int> dist(n, INF);
    dist[source] = 0;
    set<int> visited;
    for (int count = 0; count < n; count++) {
        int u = -1;
        // 找到未访问过且距离源点最短的顶点
        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end() && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        visited.insert(u);
        // 更新与u相邻顶点的距离
        for (int v = 0; v < n; v++) {
            if (graph[u][v]!= INF && visited.find(v) == visited.end()) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    // 输出从源点到各个顶点的最短距离
    cout << "从源点 " << source << " 到各顶点的最短距离如下：" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "到顶点 " << i << " 不可达" << endl;
        } else {
            cout << "到顶点 " << i << " 的最短距离为: " << dist[i] << endl;
        }
    }
}

int main() {
    int n = 5;
    // 初始化邻接矩阵表示的图示例（可根据实际情况修改图的连接关系和权值）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
    graph[0][1] = 2;
    graph[0][3] = 6;
    graph[1][2] = 3;
    graph[1][3] = 8;
    graph[1][4] = 5;
    graph[2][4] = 7;
    graph[3][4] = 9;

    int source = 0;
    dijkstra(source, n);
    return 0;
}
```

**代码解释**：

- **`dijkstra` 函数**：
    - 首先创建一个向量 `dist`，用于记录从源点到各个顶点的距离，初始值都设为无穷大 `INF`，除了源点本身（由参数 `source` 指定）设为 `0`，表示初始时假设到其他顶点都不可达，只有到源点自己的距离为 `0`。同时创建一个集合 `visited`，用于标记已经访问过的顶点，初始为空。
    - 接着进入一个循环，循环次数为图的顶点数量 `n`，每次循环执行以下操作：
        - 通过一个内层循环找到未被访问过（`visited.find(i) == visited.end()`）且到源点距离最短（通过比较 `dist[i]` 的值，`u == -1 || dist[i] < dist[u]` 这个条件来判断，初始 `u` 为 `-1`，后续不断更新为距离更小的顶点）的顶点 `u`，这一步就是贪心选择的体现，每次都选择当前距离源点最近的未访问顶点。
        - 将找到的顶点 `u` 加入到已访问集合 `visited` 中，表示已经确定了从源点到该顶点的最短距离（至少当前是最短的，后续不会再改变，因为权值是非负的）。
        - 然后通过另一个内层循环遍历所有顶点 `v`，对于与顶点 `u` 相邻（`graph[u][v]!= INF`）且还未被访问过（`visited.find(v) == visited.end()`）的顶点，更新它们到源点的距离（`dist[v]`），取当前记录的距离和通过顶点 `u` 中转过来的距离（`dist[u] + graph[u][v]`）中的最小值，这一步是利用了已经找到的较短路信息来不断优化其他顶点到源点的距离，符合贪心的逐步优化过程。
    - 循环结束后，通过一个循环遍历所有顶点，根据 `dist` 向量中的值输出从源点到各个顶点的最短距离情况，如果值为 `INF` 则表示不可达，否则输出具体的最短距离数值。

- **`main` 函数**：
    - 首先定义了图的顶点数量 `n`（这里以 `5` 个顶点为例，可以根据实际情况修改），然后初始化邻接矩阵 `graph`，将所有元素初始化为无穷大，表示初始时各顶点之间都未连通（不可达），接着手动设置一些边的连接关系和相应的权值，模拟一个具体的图结构（这里可以根据实际需求修改图的边和权值情况）。
    - 再指定源点 `source`（这里设为 `0`，也可按需改变），最后调用 `dijkstra` 函数来计算并输出从指定源点到其他各个顶点的最短距离。

Dijkstra算法的贪心策略在于每次都选择当前距离源点最近的未访问顶点，然后利用这个顶点来更新其相邻未访问顶点到源点的距离，通过不断重复这个过程，逐步确定从源点到所有顶点的最短路径，其依赖于图中边权值非负这一条件保证了贪心选择的正确性，利用了最优子结构性质和贪心选择性质来高效地解决单源最短路径问题，不过在实际应用中，对于大规模图等情况，也常采用一些优化手段，比如使用优先队列来提高查找最短距离顶点的效率等。

### 示例十：区间调度问题（另一种形式）

假设有多个区间，每个区间都有起始时间和结束时间，现在要选择一些互不重叠的区间，使得选择的区间数量最多。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 区间结构体，包含起始时间和结束时间
struct Interval {
    int start;
    int end;
};

// 比较函数，用于按照区间结束时间从小到大排序
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

// 贪心算法实现区间调度
int intervalScheduling(vector<Interval>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    // 先按照区间结束时间对区间进行排序
    sort(intervals.begin(), intervals.end(), compareIntervals);
    int count = 1;
    int lastEnd = intervals[0].end;
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].start >= lastEnd) {
            count++;
            lastEnd = intervals[i].end;
        }
    }
    return count;
}

int main() {
    vector<Interval> intervals = {
        {1, 4},
        {2, 5},
        {3, 6},
        {4, 7},
        {5, 8},
        {6, 9},
        {7, 10},
        {8, 11},
        {9, 12},
        {10, 13},
        {11, 14}
    };
    int maxCount = intervalScheduling(intervals);
    cout << "最多可选择的互不重叠区间数量为: " << maxCount << endl;
    return 0;
}
```

**代码解释**：

- **`compareIntervals` 函数**：
    - 这是一个自定义的比较函数，用于 `sort` 函数对区间数组进行排序时的比较规则。按照区间结束时间从小到大排序，使得结束时间早的区间排在前面，这是贪心策略的关键，因为优先选择结束时间早的区间，能为后续选择更多互不重叠的区间腾出更多时间空间。

- **`intervalScheduling` 函数**：
    - 首先判断区间数组 `intervals` 是否为空，如果为空则直接返回 `0`，表示没有区间可供选择，可选择数量为 `0`。
    - 接着调用 `sort` 函数，根据自定义的比较函数 `compareIntervals` 对区间数组进行排序，让区间按照结束时间升序排列。
    - 初始化一个变量 `count` 为 `1`，表示已经选择了第一个区间（因为至少会选择一个最早结束的区间），同时记录第一个区间的结束时间 `lastEnd`。
    - 通过一个循环遍历排序后的区间数组（从第二个区间开始，索引为 `1`），对于每个区间，判断其起始时间是否大于等于上一个选择区间的结束时间，如果满足这个条件，说明该区间与已选区间没有重叠，可以选择这个区间，此时将 `count` 加 `1`，并更新 `lastEnd` 为当前区间的结束时间。
    - 循环结束后，`count` 就是能够选择的最多互不重叠区间的数量，最后返回这个值。

- **`main` 函数**：
    - 首先定义了一个区间数组 `intervals`，包含了多个区间的起始时间和结束时间信息（这里可以根据实际情况修改区间的具体时间安排）。然后调用 `intervalScheduling` 函数计算最多可选择的互不重叠区间数量，并输出展示给用户。

贪心算法在这个区间调度问题中，通过先对区间按结束时间排序，然后每次选择结束时间最早且与已选区间不重叠的区间这一贪心策略，能够逐步构建出数量最多的互不重叠区间集合，符合问题本身具有的贪心选择性质和最优子结构性质，从而有效地解决此类区间选择以达到数量最优的问题。

这些不同的示例全面展示了贪心算法在各类优化问题中的应用，通过合理定义贪心策略，根据问题的特点做出局部最优选择，并利用最优子结构性质逐步构建全局最优解（或接近全局最优解的结果），不过需要谨慎判断问题是否确实适合贪心算法，因为并非所有问题都能通过简单的贪心策略来有效解决，需要满足相应的性质条件才行。 



总之，贪心算法在很多领域都有着广泛的应用，只要能够准确把握问题的特性并设计出合适的贪心策略，就能高效地处理诸如资源分配、路径规划、任务安排等多方面的实际问题，为提高效率、优化方案等提供有力的算法支持。 