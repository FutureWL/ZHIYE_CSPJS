以下是使用C++实现广度优先搜索（Breadth-First Search，BFS）算法的几个示例，分别应用在不同的数据结构场景下，包括图和树结构等：

### 一、图的广度优先搜索（使用邻接表表示图）

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 图的邻接表表示，这里用vector的vector来模拟邻接表，每个元素存储其相邻节点的索引
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // 添加边的函数，用于构建图的连接关系
    void addEdge(int source, int destination) {
        adjList[source].push_back(destination);
        adjList[destination].push_back(source);  // 无向图需要双向添加
    }

    // 广度优先搜索函数
    void bfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> vertexQueue;

        visited[startVertex] = true;
        vertexQueue.push(startVertex);

        while (!vertexQueue.empty()) {
            int currentVertex = vertexQueue.front();
            vertexQueue.pop();
            cout << currentVertex << " ";

            for (int adjacentVertex : adjList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    vertexQueue.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "广度优先搜索结果（从顶点0开始）：" << endl;
    g.bfs(0);
    cout << endl;

    return 0;
}
```

**代码解释**：

- **`Graph` 类**：
    - `numVertices` 成员变量用于记录图的顶点数量，`adjList` 是一个二维向量，用于模拟图的邻接表，其中 `adjList[i]` 存储顶点 `i` 的所有相邻顶点的索引。
    - `addEdge` 函数用于在图中添加边，在无向图的情况下，需要同时将目标顶点添加到源顶点的邻接表中，以及将源顶点添加到目标顶点的邻接表中，以此来构建图的连接关系。

- **`bfs` 函数**：
    - 首先创建一个布尔类型的向量 `visited`，长度为图的顶点数量，初始值都设为 `false`，用于记录每个顶点是否被访问过。同时创建一个队列 `vertexQueue`，用于存储待访问的顶点。
    - 将起始顶点 `startVertex` 标记为已访问（`visited[startVertex] = true`），并将其加入队列 `vertexQueue.push(startVertex)`。
    - 进入 `while` 循环，只要队列不为空，就执行以下操作：
        - 取出队列头部的顶点 `currentVertex = vertexQueue.front(); vertexQueue.pop();`，并输出该顶点的值（这里只是简单输出，实际应用中可以根据需求进行更复杂的操作）。
        - 通过一个循环遍历当前顶点的所有相邻顶点（`for (int adjacentVertex : adjList[currentVertex])`），对于每个未被访问过的相邻顶点（`!visited[adjacentVertex]`），将其标记为已访问（`visited[adjacentVertex] = true`），然后将其加入队列（`vertexQueue.push(adjacentVertex)`），以便后续按顺序访问。这样就实现了一层一层地对图进行遍历，也就是广度优先搜索的过程。

- **`main` 函数**：
    - 首先创建一个具有 `6` 个顶点的 `Graph` 对象 `g`，然后通过调用 `addEdge` 函数手动构建图的边的连接关系，形成一个具体的无向图结构。最后调用 `g.bfs` 函数，从顶点 `0` 开始进行广度优先搜索，并输出搜索结果，展示按照广度优先顺序访问的顶点序列。

### 二、树的广度优先搜索（使用二叉树节点结构体表示树）

```cpp
#include <iostream>
#include <queue>

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 树的广度优先搜索函数
void bfs(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* currentNode = nodeQueue.front();
        nodeQueue.pop();
        std::cout << currentNode->val << " ";

        if (currentNode->left!= NULL) {
            nodeQueue.push(currentNode->left);
        }

        if (currentNode->right!= NULL) {
            nodeQueue.push(currentNode->right);
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "树的广度优先搜索结果：" << endl;
    bfs(root);
    std::cout << endl;

    return 0;
}
```

**代码解释**：

- **`TreeNode` 结构体**：
    - 定义了二叉树节点的结构，包含一个整数值 `val`，以及分别指向左子树和右子树的指针 `left` 和 `right`，方便构建二叉树结构。

- **`bfs` 函数**：
    - 首先判断根节点 `root` 是否为空，如果为空则直接返回，因为空树不需要进行搜索操作。
    - 创建一个队列 `nodeQueue`，用于存储待访问的二叉树节点，将根节点 `root` 加入队列（`nodeQueue.push(root)`）。
    - 进入 `while` 循环，只要队列不为空，就执行以下操作：
        - 取出队列头部的节点 `currentNode = nodeQueue.front(); nodeQueue.pop();`，并输出该节点的值（这里同样是简单输出展示访问顺序，实际可按需操作）。
        - 检查当前节点的左子树是否存在（`currentNode->left!= NULL`），如果存在，则将左子树节点加入队列（`nodeQueue.push(currentNode->left)`）；同样地，检查右子树是否存在（`currentNode->left!= NULL`），若存在则将右子树节点加入队列（`nodeQueue.push(currentNode->right)`）。通过这样的操作，就能实现按照树的层次顺序，一层一层地对二叉树进行遍历，也就是广度优先搜索的过程。

- **`main` 函数**：
    - 首先手动构建一个简单的二叉树结构，通过创建节点对象并设置它们之间的父子关系来形成一棵二叉树。然后调用 `bfs` 函数对构建好的二叉树进行广度优先搜索，并输出搜索结果，展示按照广度优先顺序访问的节点值序列。

广度优先搜索算法在图和树等数据结构中有着广泛的应用，它能够按照距离起始点（或根节点）由近到远的顺序遍历所有可达的节点，常用于查找最短路径（无权图情况下）、判断图的连通性、遍历树的层次结构等场景。在实际应用中，还可以根据具体需求对算法进行适当的扩展和优化，比如记录节点的深度信息、对搜索过程中的节点进行特定的操作等。 



这些示例展示了广度优先搜索算法在不同数据结构场景下的基本实现方式，通过队列来辅助实现按层遍历的逻辑，从而达到广度优先搜索的效果，希望能帮助你更好地理解和运用该算法。 