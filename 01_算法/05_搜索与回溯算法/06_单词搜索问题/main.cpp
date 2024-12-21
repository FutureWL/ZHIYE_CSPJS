#include <iostream>
#include <vector>

using namespace std;

// 四个方向的偏移量，用于遍历上下左右相邻单元格
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

// 判断坐标 (x, y) 是否在网格范围内
bool inBoard(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

// 回溯函数，用于在网格中搜索单词
bool wordSearchUtil(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited) {
    if (index == word.length()) {
        // 当已经匹配完单词的所有字符，说明找到了单词，返回true
        return true;
    }

    int m = board.size();
    int n = board[0].size();
    if (!inBoard(x, y, m, n) || visited[x][y] || board[x][y] != word[index]) {
        return false;
    }

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (wordSearchUtil(board, word, index + 1, newX, newY, visited)) {
            return true;
        }
    }
    visited[x][y] = false;
    return false;
}

// 解决单词搜索问题的主函数
bool wordSearch(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (wordSearchUtil(board, word, 0, i, j, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    bool result = wordSearch(board, word);
    if (result) {
        cout << "单词存在于网格中" << endl;
    }
    else {
        cout << "单词不存在于网格中" << endl;
    }
    return 0;
}