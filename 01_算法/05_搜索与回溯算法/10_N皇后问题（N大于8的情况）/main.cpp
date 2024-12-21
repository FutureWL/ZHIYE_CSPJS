#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 检查在当前位置(row, col)放置皇后是否合法
bool isSafe(vector<string>& board, int row, int col, int n) {
    // 检查同一列是否有皇后冲突
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // 检查左上方对角线是否有皇后冲突
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // 检查右上方对角线是否有皇后冲突
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// 回溯函数，用于放置皇后并寻找可行解
void solveNQueensUtil(vector<string>& board, int row, int n, vector<vector<string>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueensUtil(board, row + 1, n, solutions);
            board[row][col] = '.';
        }
    }
}

// 解决N皇后问题的主函数
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveNQueensUtil(board, 0, n, solutions);
    return solutions;
}

int main() {
    int n = 10;  // 这里可以修改N的值，比如设置为10表示十皇后问题
    vector<vector<string>> solutions = solveNQueens(n);
    cout << "N皇后问题（N = " << n << "）的解的个数为: " << solutions.size() << endl;
    for (vector<string> solution : solutions) {
        for (string row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
