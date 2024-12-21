#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 构建图的邻接表结构
class Graph {
private:
    int V;  // 图的顶点数量
    vector<vector<int>> adj;  // 邻接表，存储每个顶点的邻接顶点

public:
    Graph(int v) : V(v), adj(v) {}

    // 添加边的函数，用于构建图的连接关系
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 深度优先搜索的辅助函数，用于递归遍历
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // 深度优先搜索的主函数，对外暴露的接口
    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(6);  // 创建一个有6个顶点的图
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "深度优先搜索结果（从顶点0开始）：" << endl;
    g.DFS(0);
    cout << endl;
    return 0;
}