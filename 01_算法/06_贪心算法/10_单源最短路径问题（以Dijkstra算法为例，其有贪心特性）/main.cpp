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
            if (graph[u][v] != INF && visited.find(v) == visited.end()) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    // 输出从源点到各个顶点的最短距离
    cout << "从源点 " << source << " 到各顶点的最短距离如下：" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "到顶点 " << i << " 不可达" << endl;
        }
        else {
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