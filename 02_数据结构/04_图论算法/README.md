1. **图的基本概念**
   - 图（Graph）是一种非线性的数据结构，由顶点（Vertex）集合和边（Edge）集合组成。顶点表示图中的节点，边表示顶点之间的关系。可以将图想象成一个由点和线构成的网络，例如社交网络中用户是顶点，用户之间的朋友关系是边；城市交通网络中城市是顶点，城市之间的道路是边。
   - 根据边是否有方向，图可以分为有向图（Directed Graph）和无向图（Undirected Graph）。在有向图中，边是有方向的，用箭头表示，从一个顶点指向另一个顶点；无向图中的边没有方向，两个顶点之间的边可以双向通行。另外，根据边是否带有权重（如距离、成本等），图又可以分为带权图（Weighted Graph）和无权图（Unweighted Graph）。

2. **图的存储方式**
   - **邻接矩阵（Adjacency Matrix）**
     - 假设图有\(n\)个顶点，那么可以使用一个\(n\times n\)的二维数组来存储图的边信息。对于无向图，如果顶点\(i\)和顶点\(j\)之间有边相连，那么矩阵中\(a[i][j]=a[j][i]=1\)（或者边的权重，如果是带权图）；对于有向图，若存在从顶点\(i\)指向顶点\(j\)的边，则\(a[i][j]=1\)（或边的权重），\(a[j][i]\)的值则根据实际情况确定。
     - 示例代码如下（以无向图为例）：
     ```cpp
     const int MAX_VERTICES = 100;
     class Graph {
     private:
         int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
         int numVertices;
     public:
         Graph(int vertices) : numVertices(vertices) {
             for (int i = 0; i < numVertices; ++i) {
                 for (int j = 0; j < numVertices; ++j) {
                     adjacencyMatrix[i][j] = 0;
                 }
             }
         }
         void addEdge(int src, int dest) {
             if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
                 adjacencyMatrix[src][dest] = 1;
                 adjacencyMatrix[dest][src] = 1;
             }
         }
     };
     ```
   - **邻接表（Adjacency List）**
     - 对于每个顶点，使用一个链表（或动态数组，如`vector`）来存储与该顶点相邻的顶点。在C++中，一个常见的实现方式是使用`vector`来存储邻接表。
     - 示例代码如下：
     ```cpp
     const int MAX_VERTICES = 100;
     class Graph {
     private:
         vector<vector<int>> adjacencyList;
         int numVertices;
     public:
         Graph(int vertices) : numVertices(vertices) {
             adjacencyList.resize(numVertices);
         }
         void addEdge(int src, int dest) {
             if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
                 adjacencyList[src].push_back(dest);
                 if (isUndirected()) {
                     adjacencyList[dest].push_back(src);
                 }
             }
         }
         bool isUndirected() {
             // 根据图的类型返回是否是无向图，这里假设是无向图返回true
             return true;
         }
     };
     ```

3. **图的遍历**
   - **深度优先搜索（Depth - First Search，DFS）**
     - 从图中的一个起始顶点开始，沿着一条路径尽可能深地访问顶点，直到无法继续或者达到目标条件，然后回溯到前一步，继续探索其他路径。可以使用栈（递归本质上也是使用栈）来实现。
     - 示例代码（以邻接表存储的无向图为例）：
     ```cpp
     class Graph {
     // 前面定义的邻接表存储的Graph类部分代码省略
     public:
         void dfs(int startVertex, vector<bool>& visited) {
             visited[startVertex] = true;
             cout << startVertex << " ";
             for (int neighbor : adjacencyList[startVertex]) {
                 if (!visited[neighbor]) {
                     dfs(neighbor, visited);
                 }
             }
         }
     };
     ```
   - **广度优先搜索（Breadth - First Search，BFS）**
     - 从起始顶点开始，先访问其所有的相邻顶点，然后再依次访问这些相邻顶点的相邻顶点，以此类推，就像一层一层地搜索。通常使用队列来实现。
     - 示例代码（以邻接表存储的无向图为例）：
     ```cpp
     class Graph {
     // 前面定义的邻接表存储的Graph类部分代码省略
     public:
         void bfs(int startVertex) {
             vector<bool> visited(numVertices, false);
             queue<int> q;
             visited[startVertex] = true;
             q.push(startVertex);
             while (!q.empty()) {
                 int currentVertex = q.front();
                 q.pop();
                 cout << currentVertex << " ";
                 for (int neighbor : adjacencyList[currentVertex]) {
                     if (!visited[neighbor]) {
                         visited[neighbor] = true;
                         q.push(neighbor);
                     }
                 }
             }
         }
     };
     ```

4. **图的应用场景**
   - **社交网络分析**：用于分析用户之间的关系，如查找用户的朋友圈、共同好友等。
   - **交通导航系统**：城市道路网络可以看作是一个图，通过图算法可以计算最短路径，为用户提供最佳的出行路线。
   - **计算机网络拓扑**：表示计算机之间的连接关系，帮助网络工程师分析网络的连通性、带宽分配等问题。