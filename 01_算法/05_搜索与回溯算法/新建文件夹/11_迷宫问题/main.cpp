#include <iostream>
#include <vector>

using namespace std;

// 四个方向的偏移量，用于遍历上下左右相邻单元格
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

// 判断坐标 (x, y) 是否在迷宫范围内```cpp
bool inMaze(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

// 回溯函数，用于在迷宫中寻找从起点到终点的路径
bool mazeSolveUtil(vector<vector<int>>& maze, int startX, int startY, int endX, int endY, vector<vector<bool>>& visited) {
    if (startX == endX && startY == endY) {
        // 当到达终点，说明找到了一条路径，返回true
        return true;
    }

    int m = maze.size();
    int n = maze[0].size();
    visited[startX][startY] = true;

    for (int i = 0; i < 4; i++) {
        int newX = startX + dx[i];
        int newY = startY + dy[i];
        if (inMaze(newX, newY, m, n) && !visited[newX][newY] && maze[newX][newY] == 0) {
            // 如果新坐标在迷宫范围内、未被访问且是可通行的
            if (mazeSolveUtil(maze, newX, newY, endX, endY, visited)) {
                return true;
            }
        }
    }
    visited[startX][startY] = false;
    return false;
}

// 解决迷宫问题的主函数
bool mazeSolve(vector<vector<int>>& maze, int startX, int startY, int endX, int endY) {
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return mazeSolveUtil(maze, startX, startY, endX, endY, visited);
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    int startX = 0, startY = 0;
    int endX = 4, endY = 4;
    if (mazeSolve(maze, startX, startY, endX, endY)) {
        cout << "存在从起点到终点的路径" << endl;
    }
    else {
        cout << "不存在从起点到终点的路径" << endl;
    }
    return 0;
}