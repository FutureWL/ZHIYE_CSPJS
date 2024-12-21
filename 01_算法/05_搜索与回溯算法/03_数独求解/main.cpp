#include <iostream>
#include <vector>

using namespace std;

// 检查在数独棋盘的(row, col)位置放置数字num是否合法
bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
    // 检查行
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // 检查列
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // 检查所在的3×3小九宫格
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// 回溯函数，用于填充数独并寻找可行解
bool solveSudokuUtil(vector<vector<char>>& board, int row, int col) {
    if (row == 9) {
        return true;
    }

    if (col == 9) {
        return solveSudokuUtil(board, row + 1, 0);
    }

    if (board[row][col] != '.') {
        return solveSudokuUtil(board, row, col + 1);
    }

    for (char num = '1'; num <= '9'; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudokuUtil(board, row, col + 1)) {
                return true;
            }
            board[row][col] = '.';
        }
    }

    return false;
}

// 解决数独问题的主函数
bool solveSudoku(vector<vector<char>>& board) {
    return solveSudokuUtil(board, 0, 0);
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '2', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '8', '1', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    if (solveSudoku(board)) {
        cout << "数独求解成功，结果如下：" << endl;
        for (vector<char> row : board) {
            for (char num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "无法求解该数独" << endl;
    }

    return 0;
}