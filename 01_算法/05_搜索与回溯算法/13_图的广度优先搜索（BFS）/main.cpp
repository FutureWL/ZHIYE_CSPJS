#include <iostream>
#include <vector>
#include <queue>

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

    // 广度优先搜索的辅助函数，用于按层遍历
    void BFSUtil(int v, vector<bool>& visited) {
        queue<int> q;
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            cout << front << " ";

            for (int neighbor : adj[front]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // 广度优先搜索的主函数，对外暴露的接口
    void BFS(int start) {
        vector<bool> visited(V, false);
        BFSUtil(start, visited);
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

    cout << "广度优先搜索结果（从顶点0开始）：" << endl;
    g.BFS(0);
    cout << endl;
    return 0;
}