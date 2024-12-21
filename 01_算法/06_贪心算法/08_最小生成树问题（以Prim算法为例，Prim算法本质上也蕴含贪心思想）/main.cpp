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
            if (graph[u][v] != INF && !inMST[v]) {
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