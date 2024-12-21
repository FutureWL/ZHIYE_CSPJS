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